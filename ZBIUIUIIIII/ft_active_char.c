/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:31:30 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/16 19:31:31 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_add;
int		g_count;
int		g_checkpoint;

void	ft_while_part_one(char *conv, char **stock, char **number, int i)
{
	if (ft_isdigit(conv[i]))
	{
		g_checkpoint = 1;
		if (*number == NULL)
			*number = malloc(strlen(conv) + 1);
		(*number)[g_count] = conv[i];
		g_count++;
		if (i == 0 && conv[i] != '0')
		{
			(*number)[g_count] = '\0';
			g_count = 0;
			*number = ft_strrev(*number);
			ft_active_all_char(conv, stock, number, i);
		}
	}
}

void	ft_while_part_two(char *conv, char **stock, char **number, int i)
{
	if (conv[i] == '-' && *number)
	{
		(*number)[g_count] = '\0';
		g_checkpoint = 1;
		g_count = 0;
		*number = ft_strrev(*number);
		ft_active_all_char(conv, stock, number, i);
	}
	if (conv[i] == '.')
		g_checkpoint = 0;
	if (conv[i] == '0' && *number && i == 0)
	{
		(*number)[g_count] = '\0';
		g_count = 0;
		*number = ft_strrev(*number);
		ft_active_all_char(conv, stock, number, i);
		g_checkpoint = 1;
	}
}

void	ft_active_all_1_char(char *conv, char **stock, int len, int i)
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
		ft_putstr_write(g_add);
		ft_putchar(**stock);
	}
	if (conv[i] == '-')
	{
		ft_putchar(**stock);
		memset(g_add, ' ', len);
		g_add[len] = '\0';
		ft_putstr_write(g_add);
	}
	if (conv[i] == '.')
		ft_putchar(**stock);
}

void	ft_active_all_char(char *conv, char **stock, char **number, int i)
{
	int		len;

	if (**stock == '\0')
		len = atoi(*number) - 1;
	else
		len = atoi(*number) - ft_strlen(*stock);
	free(*number);
	*number = NULL;
	if (len <= 0)
	{
		ft_putchar(**stock);
		return ;
	}
	g_add = malloc(len + 1);
	ft_active_all_1_char(conv, stock, len, i);
}

void	ft_active_char(char *stock, char *conv)
{
	int		i;
	char	*number;

	i = ft_strlen(conv);
	number = NULL;
	g_count = 0;
	g_checkpoint = 0;
	i--;
	if (strchr(conv, '.') && conv[0] == '0')
		conv = ft_delete_zero(conv);
	while (i >= 0)
	{
		ft_while_part_one(conv, &stock, &number, i);
		ft_while_part_two(conv, &stock, &number, i);
		i--;
	}
	if (g_checkpoint == 0)
		ft_putchar(*stock);
}
