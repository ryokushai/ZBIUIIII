/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:45:57 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/20 08:58:26 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_printf;
int	g_len;

void	ft_active_active(char *str, char *stock, char *conv, va_list arg)
{
	if (*str == '%')
	{
		stock = malloc(2);
		stock[0] = '%';
		stock[1] = '\0';
		ft_active_pour(stock, conv);
	}
	if (*str == 'c' || *str == 's' || *str == 'd' || *str == 'i')
	{
		ft_condition_2(stock, conv, str, arg);
	}
	if (*str == 'u' || *str == 'x' || *str == 'X' || *str == 'p')
	{
		ft_condition_1(stock, conv, str, arg);
	}
}

char	**ft_etoile(va_list arg, int *count)
{
	char	**etoile;
	int		e;

	e = 0;
	etoile = malloc(sizeof(char *) * 3);
	while (*count)
	{
		etoile[e] = ft_itoa(va_arg(arg, int));
		g_len = strlen(etoile[e]) + (g_len);
		e++;
		(*count) -= 1;
	}
	etoile[e] = 0;
	return (etoile);
}

char	*ft_work_etoile(int num, char *conv, char **etoile)
{
	char	*conv2;
	int		i;
	int		e;
	int		z;
	int		j;

	e = 0;
	i = 0;
	z = 0;
	j = 0;
	conv2 = malloc(num + g_len + 1);
	while (conv[i])
	{
		z = 0;
		while (conv[i] != '*' && conv[i])
			conv2[j++] = conv[i++];
		while (etoile[e] && etoile[e][z])
			conv2[j++] = etoile[e][z++];
		e++;
		if (conv[i])
			i++;
	}
	conv2[j] = '\0';
	return (conv2);
}

int		ft_work(va_list arg, char *str)
{
	char	*conv;
	int		num;
	char	*stock;
	int		count;
	char	**etoile;

	g_len = 0;
	while (*str != '\0')
	{
		ft_while(&str, &conv, &num, &count);
		if (!(*str))
			return (0);
		etoile = ft_etoile(arg, &count);
		conv = ft_work_etoile(num, conv, etoile);
		ft_active_active(str, stock, conv, arg);
		str++;
		ft_free(&conv, &stock);
	}
	return (0);
}

int		ft_printf(char *format, ...)
{
	va_list	arg;
	char	*str;

	va_start(arg, format);
	str = format;
	ft_work(arg, str);
	va_end(arg);
	return (g_printf);
}
