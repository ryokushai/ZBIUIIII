/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 22:12:36 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/11 09:22:07 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_add;
int		g_count;

void	ft_while_part_five_int(char **g_add, char **stock, int len)
{
	if (*stock[0] == '-')
	{
		*stock = ft_delete_minus(*stock);
		memset(*g_add, '0', len);
		(*g_add)[len] = '\0';
		*g_add = ft_stock("-", *g_add);
		*stock = ft_stock(*g_add, *stock);
	}
	else
	{
		memset(*g_add, '0', len);
		(*g_add)[len] = '\0';
		*stock = ft_stock(*g_add, *stock);
	}
}

void	ft_while_part_four_int(char **g_add, char **stock, int len)
{
	*g_add = malloc(len + 2);
	if (*stock[0] == '-')
	{
		len++;
		*stock = ft_delete_minus(*stock);
		memset(*g_add, '0', len);
		(*g_add)[len] = '\0';
		*g_add = ft_stock("-", *g_add);
		*stock = ft_stock(*g_add, *stock);
	}
	else
	{
		memset(*g_add, '0', len);
		(*g_add)[len] = '\0';
		*stock = ft_stock(*g_add, *stock);
	}
}

void	ft_while_part_three_int(char *conv, char **stock, char **number, int i)
{
	if (conv[i + 1] == '-' && **stock == '0')
		**stock = '0';
	else
	{
		if (*number)
			(*number)[g_count] = '\0';
		if ((*number == NULL || atoi(*number) == 0) && ft_check_zero(*stock))
		{
			if (*number == NULL)
			{
				*number = malloc(2);
				(*number)[0] = '0';
				(*number)[1] = '\0';
			}
			g_count = 0;
			ft_active_all(conv, stock, number, i);
		}
		else if (*number)
		{
			(*number)[g_count] = '\0';
			g_count = 0;
			*number = ft_strrev(*number);
			ft_active_all(conv, stock, number, i);
		}
	}
}

void	ft_while_part_two_int(char *conv, char **stock, char **number, int i)
{
	if (conv[i] == '-' && *number)
	{
		(*number)[g_count] = '\0';
		g_count = 0;
		if (ft_skip_minus(conv, i))
		{
			*number = ft_strrev(*number);
			ft_active_all(conv, stock, number, i);
		}
		else
		{
			*number = NULL;
			free(*number);
		}
	}
}

void	ft_while_part_one_int(char *conv, char **stock, char **number, int i)
{
	if (conv[i] == '0' && *number && i == 0)
	{
		(*number)[g_count] = '\0';
		g_count = 0;
		*number = ft_strrev(*number);
		ft_active_all(conv, stock, number, i);
	}
	else if (ft_isdigit(conv[i]))
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
			ft_active_all(conv, stock, number, i);
		}
	}
}

void	ft_active_all_1(char *conv, char **stock, int len, int i)
{
	g_add = malloc(len + 1);
	if (conv[i] == '0')
		ft_while_part_five_int(&g_add, stock, len);
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
		ft_while_part_four_int(&g_add, stock, len);
}

void	ft_active_all(char *conv, char **stock, char **number, int i)
{
	int	len;
	int	j;

	if (atoi(*number) == 0 && atoi(*stock) == 0 && (j = ft_check_zero(*stock)))
	{
		if (j == 2)
			(*stock)[2] = '\0';
		else
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
	if (*stock[0] == '-')
		g_add = malloc(len + 2);
	else
		g_add = malloc(len + 1);
	ft_active_all_1(conv, stock, len, i);
}

void 	ft_active(char *stock, char *conv)
{
	int		i;
	char	*number;
	char	*xtr;

	i = ft_strlen(conv);
	number = NULL;
	g_count = 0;
	i--;
	xtr = strchr(conv, '.');
	if ((xtr && conv[0] == '0' && xtr[1] != '-') || (conv[0] == '0' && conv[1] == '-'))
		conv = ft_delete_zero(conv);
	while (i >= 0)
	{
		ft_while_part_one_int(conv, &stock, &number, i);
		ft_while_part_two_int(conv, &stock, &number, i);
		if (conv[i] == '.')
		{
			ft_while_part_three_int(conv, &stock, &number, i);
		}
		i--;
	}
	ft_putstr_write(stock);
}
