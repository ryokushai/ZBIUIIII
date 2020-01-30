/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:47:58 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/11 13:37:07 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_adress(unsigned long long n)
{
	char	*ptr;
	char	*str;

	str = ft_itohexa3(n);
	ptr = ft_stock("0x", str);
	return (ptr);
}
