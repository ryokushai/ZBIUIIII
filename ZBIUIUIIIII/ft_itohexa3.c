/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohexa3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:33:02 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/24 14:33:04 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*ft_itohexa3(unsigned long long  n)
{
	unsigned long long  	f;
	int				len;
	char			*dest;
	char			*tab;
	char			s;
	unsigned long long 				i;
	unsigned long long 				j;

	j = 0;
	tab = "0123456789abcdef";
	len = ft_lenght(n);
	f = n;
	if (n == 0)
	{
		dest = malloc(2);
		dest[0] = '0';
		dest[1] = '\0';
		return dest;
	}
	dest = malloc(sizeof(char) * (len + 1));
	while (f != 0)
	{
		i = f % 16;
		f = f / 16;
		s = tab[i];
		dest[j] = s;
		j++;
	}
	dest = ft_strrev(dest);
	return (dest);
}
