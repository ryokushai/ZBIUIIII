/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:16:35 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/07 20:55:31 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flags(char *str)
{
	char	*tab;
	char	*flags;
	int		count;
	
	count = 0;
	tab = "-0";
	while (ft_strchr(tab,str[count]))
	{
		count++;
	}
	flags = malloc(sizeof(char) * (count + 1));	
	ft_strlcpy(flags, str, count + 1);
	return flags;
}
