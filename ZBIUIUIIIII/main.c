/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:08:57 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/20 08:45:02 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	//printf("%d\n",printf("ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));
	//printf("%d\n",printf("ca%----4c%1c va %10c%-c ??\n",'\0','\n',(char)564,0));
	
	//printf("%d\n",ft_printf("ca%----4c%1c va %10c%-c ??\n",'\0','\n',(char)564,0));
	//printf("%p\n", (void *)UINT64_MAX);
	//ft_printf("hello ca%----4c %1c va %13c%-c ??", '\0', '\n', (char)564, 0);
	printf("a%-4sa\n","abc");
	ft_printf("a%-4sa", "abc");
	//ft_printf("%.3%l");
	//ft_printf("%*s %*d %*c",3, "hello",2,10,1,'g');
}	

