/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:36:50 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/09 22:10:42 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev2(char *str)
{
	int		i;
	int		k;
	int		j;
	char	temp;

	i = 1;
	while (str[i] != '\0')
	{
		i++;
	}
	k = 1;
	j = i - 1;
	while (k < j)
	{
		temp = str[k];
		str[k] = str[j];
		str[j] = temp;
		k++;
		j--;
	}
	return (str);
}

char	*ft_stock_int(int n, char *dest)
{
	unsigned int	f;
	int				i;
	char			s;

	i = 0;
	f = n;
	if (n < 0)
	{
		i = 1;
		dest[0] = '-';
		f = f * (-1);
	}
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

char		*ft_itoa(int n)
{
	int		len;
	char	*dest;

	len = ft_lenght(n);
	if (n < 0)
	{
		if (!(dest = malloc(sizeof(char) * (len + 2))))
			return (NULL);
	}
	else if (n == 0)
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
	dest = ft_stock_int(n, dest);
	return (n < 0 ? ft_strrev2(dest) : ft_strrev(dest));
}