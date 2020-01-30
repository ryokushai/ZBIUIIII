/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_pourcentage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:24:41 by haboussi          #+#    #+#             */
/*   Updated: 2020/01/17 18:24:44 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_add;
int		g_checkpoint;
int		g_count;

void	ft_while_part_one_p(char *conv, char **stock, char **number, int i)
{
	if (ft_isdigit(conv[i]))
	{
		g_checkpoint = 1;
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
			ft_active_all_pour(conv, stock, number, i);
		}
	}
}

void	ft_while_part_two_p(char *conv, char **stock, char **number, int i)
{
	if (conv[i] == '-' && *number)
	{
		(*number)[g_count] = '\0';
		g_checkpoint = 1;
		g_count = 0;
		*number = ft_strrev(*number);
		ft_active_all_char(conv, stock, number, i);
	}
	if (conv[i] == '0' && *number && i == 0 && conv[i + 1] != '-')
	{
		(*number)[g_count] = '\0';
		g_count = 0;
		*number = ft_strrev(*number);
		ft_active_all_pour(conv, stock, number, i);
		g_checkpoint = 1;
	}
}

void	ft_active_all_1_pour(char *conv, char **stock, int len, int i)
{
	if (conv[i] == '0')
	{
		memset(g_add, '0', len);
		g_add[len] = '\0';
		ft_putstr_write(g_add);
		ft_putchar(**stock);
	}
	else if (ft_isdigit(conv[i]))
	{
		memset(g_add, ' ', len);
		g_add[len] = '\0';
		ft_putstr_write(g_add);
		ft_putchar(**stock);
	}
	if (conv[i] == '-')
	{
		ft_putchar(**stock);
		memset(g_add, ' ', len);
		g_add[len] = '\0';
		ft_putstr_write(g_add);
		ft_putchar(**stock);
	}
}

void	ft_active_all_pour(char *conv, char **stock, char **number, int i)
{
	int		len;

	len = atoi(*number) - 1;
	free(*number);
	*number = NULL;
	if (len <= 0)
	{
		ft_putchar(**stock);
		return ;
	}
	g_add = malloc(len + 1);
	ft_active_all_1_pour(conv, stock, len, i);
}

void	ft_active_pour(char *stock, char *conv)
{
	int		i;
	char	*number;

	i = ft_strlen(conv);
	number = NULL;
	g_count = 0;
	g_checkpoint = 0;
	i--;
	if (strchr(conv, '.'))
		conv = ft_delete_point(conv);
	while (i >= 0)
	{
		ft_while_part_one_p(conv, &stock, &number, i);
		ft_while_part_two_p(conv, &stock, &number, i);
		i--;
	}
	if (g_checkpoint == 0)
		ft_putchar(*stock);
}
