/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:01:32 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/24 15:01:36 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_check_zero(char *stock)
{
    int i;

    i = 0;
    while(stock[i])
    {
       if (ft_isdigit(stock[i]))
       {
           i++;
       }
       else
       {
           return 0;
       }
    }
    if (atoi(stock) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}