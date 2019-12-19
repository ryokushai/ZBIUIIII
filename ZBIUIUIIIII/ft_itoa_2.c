/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 03:11:24 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/16 03:11:26 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


char	*ft_stock_int_u(unsigned int  n, char *dest)
{
	unsigned int	f;
	int				i;
	char			s;

	i = 0;
	f = n;
	while (f != 0)
	{
		s = f % 10 + '0';
		f = f / 10;
		dest[i] = s;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_itoa_2(unsigned int n)
{
	int		len;
	char	*dest;

	len = ft_lenght(n);
	if (n == 0)
	{
		if (!(dest = malloc(sizeof(char) * 2)))
			return (NULL);
		dest[0] = '0';
		dest[1] = '\0';
		return (dest);
	}
	else
	{
		if (!(dest = malloc(sizeof(char) * (len + 1))))
			return (NULL);
	}
	dest = ft_stock_int_u(n, dest);
	return ft_strrev(dest);
}