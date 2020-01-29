/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:55:44 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/20 08:54:45 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conditions(char *str)
{
	char	*tab;
	char	*result;
	char	*ktr;
	int		count;

	count = 0;
	ktr = strdup(str);
	tab = "cspidu%xX";
	while (*ktr)
	{
		if (!(strchr(tab, *ktr)))
		{
			count++;
		}
		else
		{
			break;
		}
		ktr++;
	}
	result = ft_substr(str, 0, count);
	return (result);
}
