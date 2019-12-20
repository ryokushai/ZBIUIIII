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

int		ft_printf(char *format, ...)
{
	va_list	arg;
	int		i;
	char	*str;
	char	*conv;
	int 	num;
	char	*stock;
	//from here
	int		e;
	int 	count;
	int		z;
	int		len = 0;
	char	**etoile;
	char	*conv2;
	int		j = 0;


	i = 0;
	va_start(arg, format);
	str = format;
	while (*str != '\0')
	{
		count = 0;
		while (*str != '%')
		{
			ft_putchar(*str);
			str++;
			if (*str == '\0')
			{
				return g_printf;
			}
		}
		str++;
		if (*str == '\0')
			return g_printf;
		conv = ft_conditions(str);	
		num = strlen(conv);
		str = str + num;
		while (conv[i])
		{
			if (conv[i] == '*')
				count++;
			i++;
		}
		e = 0;
		etoile = malloc(sizeof(char *) * 3);
		while (count--)
		{
			etoile[e] = ft_itoa(va_arg(arg, int));
			len = strlen(etoile[e]) + len;
			e++;
		}
		etoile[e] = 0;
		conv2 = malloc(num + len + 1);
		i = 0;
		e = 0;
		while (conv[i])
		{
			z = 0;
			while (conv[i] != '*' && conv[i])
			{
				conv2[j++] = conv[i++];
			}
			while (etoile[e] && etoile[e][z])
			{
				conv2[j++] = etoile[e][z++];
			}
			e++;
			i++;
		}
		conv2[j] = '\0';
		if (*str == 'c')
		{
			stock = ft_char(va_arg(arg, int));
			ft_active_char(stock, conv2);
		}	
		if (*str == 's')
		{
			stock = va_arg(arg, char *);
			ft_active_string(stock,conv2);
		}
		if (*str == 'd' || *str == 'i')
		{
			stock = ft_itoa(va_arg(arg, int));
			ft_active(stock, conv2);
		}
		if (*str == 'u')
		{
			stock = ft_itoa_2(va_arg(arg, unsigned int));
			ft_active(stock,conv2);
		}
		if (*str == 'x')
		{
			stock = ft_itohexa(va_arg(arg, unsigned long long));
			ft_active(stock, conv2);
		}
		if (*str == 'X')
		{
			stock = ft_itohexa2(va_arg(arg, unsigned long long));
			ft_active(stock, conv2);
		}
		if (*str == 'p')
		{
			stock = ft_adress(va_arg(arg, unsigned long long));
			ft_active(stock, conv2);
		}
		str++;
		conv = NULL;
		stock = NULL;
		conv2 = NULL;
		free(conv);
		free(stock);
		free(conv2);
	}
	return g_printf;
	va_end(arg);
}
