/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:19:36 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/11 10:47:08 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_delete_zero(char *conv)
{
	int		len;
	char	*result;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len = ft_strlen(conv);
	result = malloc(len);
	while (conv[i])
	{
		result[j++] = conv[i++];
	}
	result[j] = '\0';
	return (result);
}

char	*ft_delete_minus(char *stock)
{
	int		len;
	char	*result;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len = ft_strlen(stock);
	result = malloc(len);
	while (stock[i])
	{
		result[j++] = stock[i++];
	}
	result[j] = '\0';
	return (result);
}

char	*ft_delete_point(char *conv)
{
	char	*result;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = ft_strlen(conv);
	result = malloc(len);
	while (conv[i] != '.')
	{
		result[j++] = conv[i++];
	}
	result[j] = '\0';
	return (result);
}
