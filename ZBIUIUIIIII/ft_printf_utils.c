/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:09:59 by haboussi          #+#    #+#             */
/*   Updated: 2020/01/29 22:10:02 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_while(char **str, char **conv, int *num, int *count)
{
	int	i;

	i = 0;
	(*count) = 0;
	while (**str != '%')
	{
		ft_putchar(**str);
		(*str) += 1;
		if (**str == '\0')
		{
			return ;
		}
	}
	(*str) += 1;
	if (**str == '\0')
		return ;
	*conv = ft_conditions(*str);
	*num = strlen(*conv);
	(*str) = (*str) + (*num);
	while ((*conv)[i])
	{
		if ((*conv)[i] == '*')
			(*count) += 1;
		i++;
	}
}

void	ft_free(char **stock, char **conv)
{
	*conv = NULL;
	*stock = NULL;
	free(*conv);
	free(*stock);
}

void	ft_condition_2(char *stock, char *conv, char *str, va_list arg)
{
	if (*str == 'c')
	{
		stock = ft_char(va_arg(arg, int));
		ft_active_char(stock, conv);
	}
	if (*str == 's')
	{
		stock = va_arg(arg, char *);
		ft_active_string(stock, conv);
	}
	if (*str == 'd' || *str == 'i')
	{
		stock = ft_itoa(va_arg(arg, int));
		ft_active(stock, conv);
	}
}

void	ft_condition_1(char *stock, char *conv, char *str, va_list arg)
{
	if (*str == 'u')
	{
		stock = ft_itoa_2(va_arg(arg, unsigned int));
		ft_active(stock, conv);
	}
	if (*str == 'x')
	{
		stock = ft_itohexa(va_arg(arg, unsigned int));
		ft_active(stock, conv);
	}
	if (*str == 'X')
	{
		stock = ft_itohexa2(va_arg(arg, unsigned int));
		ft_active(stock, conv);
	}
	if (*str == 'p')
	{
		stock = ft_adress(va_arg(arg, unsigned long long));
		ft_active(stock, conv);
	}
}
