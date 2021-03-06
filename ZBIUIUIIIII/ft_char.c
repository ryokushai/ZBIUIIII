/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 05:56:28 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/16 05:56:28 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(char s)
{
	char	*str;

	str = malloc(2);
	if (s == '\0')
	{
		*str = '\0';
		return (str);
	}
	str[1] = '\0';
	str[0] = s;
	return (str);
}
