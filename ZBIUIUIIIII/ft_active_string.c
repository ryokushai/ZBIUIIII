/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:55:34 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/20 08:33:02 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_add;
int		g_count;

void	ft_while_part_one_s(char *conv, char **stock, char **number, int i)
{
	if (ft_isdigit(conv[i]))
	{
		if (*number == NULL)
		{
			*number = malloc(strlen(conv) + 1);
		}
		(*number)[g_count] = conv[i];
		g_count++;
		if (i == 0 && conv[i] != '0')
		{
			(*number)[g_count] = '\0';
			g_count = 0;
			*number = ft_strrev(*number);
			ft_active_all_string(conv, stock, number, i);
		}
	}
}

void	ft_while_part_two_s(char *conv, char **stock, char **number, int i)
{
	if (conv[i] == '-' && *number && ft_skip_minus(conv, i))
	{
		(*number)[g_count] = '\0';
		g_count = 0;
		*number = ft_strrev(*number);
		ft_active_all_string(conv, stock, number, i);
	}
	else if (!(ft_skip_minus(conv, i)) && conv[i] == '-')
	{
		free(*number);
		*number = NULL;
		g_count = 0;
	}
}

void	ft_while_part_three_s(char *conv, char **stock, char **number, int i)
{
	if (conv[i] == '.' && conv[i + 1] != '-')
	{
		if ((*number == NULL || atoi(*number) == 0) && atoi(*stock) == 0)
		{
			if (*number == NULL)
			{
				(*number) = malloc(1);
				(*number)[0] = '0';
				(*number)[1] = '\0';
			}
		}
		(*number)[g_count] = '\0';
		g_count = 0;
		*number = ft_strrev(*number);
		ft_active_all_string(conv, stock, number, i);
	}
}

int		ft_skip_minus(char *conv, int i)
{
	while (i >= 0)
	{
		if (conv[i] != '-')
		{
			return (0);
		}
		i--;
	}
	return (1);
}

void	ft_active_all_1_string(char *conv, char **stock, int len, int i)
{
	if (conv[i] == '0')
	{
		memset(g_add, '0', len);
		g_add[len] = '\0';
		*stock = ft_stock(g_add, *stock);
	}
	else if (ft_isdigit(conv[i]))
	{
		memset(g_add, ' ', len);
		g_add[len] = '\0';
		*stock = ft_stock(g_add, *stock);
	}
	if (conv[i] == '-')
	{
		memset(g_add, ' ', len);
		g_add[len] = '\0';
		*stock = ft_stock(*stock, g_add);
	}
	if (conv[i] == '.')
		*stock = ft_trim(*stock, len);
}

void	ft_active_all_string(char *conv, char **stock, char **number, int i)
{
	int		len;

	if (conv[i] == '.')
	{
		len = atoi(*number);
		g_add = malloc(atoi(*number));
		ft_active_all_1_string(conv, stock, len, i);
		free(*number);
		*number = NULL;
		return ;
	}
	if (atoi(*number) == 0 && atoi(*stock) == 0)
	{
		*stock = "";
		free(*number);
		*number = NULL;
		return ;
	}
	len = atoi(*number) - ft_strlen(*stock);
	free(*number);
	*number = NULL;
	if (len <= 0)
		return ;
	g_add = malloc(len + 1);
	ft_active_all_1_string(conv, stock, len, i);
}

void	ft_active_string(char *stock, char *conv)
{
	int		i;
	char	*number;

	i = ft_strlen(conv);
	number = NULL;
	g_count = 0;
	i--;
	if (stock == NULL)
		stock = ft_null(stock);
	if (strchr(conv, '.') && conv[0] == '0')
		conv = ft_delete_zero(conv);
	while (i >= 0)
	{
		ft_while_part_one_s(conv, &stock, &number, i);
		ft_while_part_two_s(conv, &stock, &number, i);
		ft_while_part_three_s(conv, &stock, &number, i);
		i--;
	}
	ft_putstr_write(stock);
}
