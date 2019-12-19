/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 23:25:55 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/16 23:25:57 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_null(char *result)
{
    
    result = malloc(7);
    result[0] = '(';
    result[1] = 'n';
    result[2] = 'u';
    result[3] = 'l';
    result[4] = 'l';
    result[5] = ')';
    result[6] = '\0';

    return result; 
}