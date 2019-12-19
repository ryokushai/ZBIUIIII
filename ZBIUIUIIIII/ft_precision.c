/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:55:50 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/08 05:45:38 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision(char *str)
{
	char	*tab;
	char	*precision;
	int		count;
	int		i;

	
	i = 0;
	count = 0;
	if(!(tab = strchr(str, '.')))
	{
		return (NULL);
	}
	tab++;
	while ((ft_isdigit(tab[i])))
	{
		count++;
		i++;
	}
	precision = malloc(sizeof(char) * (count + 1));
	ft_strlcpy(precision, tab, count + 1);
	return precision;
}
