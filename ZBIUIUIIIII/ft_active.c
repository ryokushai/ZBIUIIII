/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 22:12:36 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/11 09:22:07 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *add;


void	ft_active_all_1(char *conv, char **stock, int len, int i)
{
	if (conv[i] == '0')
	{
		if (*stock[0] == '-')
		{
			*stock = ft_delete_minus(*stock);
			ft_putchar('-');
			memset(add, '0', len);
			*stock = ft_stock(add, *stock);
		}
		else
		{
			memset(add, '0', len);
			*stock = ft_stock(add, *stock);
		}
		/*
		memset(add, '0', len);
		*stock = ft_stock(add, *stock);
		*/
	}
	else if (ft_isdigit(conv[i]))
	{
		
		memset(add, ' ', len);
		*stock = ft_stock(add, *stock);
		
	
	}
	if (conv[i] == '-')
	{
		memset(add, ' ', len);
		*stock = ft_stock(*stock, add);
	
	}
	if (conv[i] == '.')
	{
		if (*stock[0] == '-')
		{
			*stock = ft_delete_minus(*stock);
			ft_putchar('-');
			memset(add, '0', len + 1);
			*stock = ft_stock(add, *stock);
		}
		else
		{
			memset(add, '0', len);
			*stock = ft_stock(add, *stock);
		}
	}
}

void	ft_active_all(char	*conv, char **stock,char **number, int i)
{
	int		len;

	//char    *add;
	
	if (atoi(*number) == 0 && atoi(*stock) == 0)
	{
		*stock = "";
		//printf("%s", *stock);
		free(*number);
		*number = NULL;
		return ;
	}
	len = atoi(*number) - ft_strlen(*stock);
	free(*number);
	*number = NULL;
	
	if (len <= 0)
		return ;
	if (*stock[0] == '-')
	{
		add = malloc(len + 2);
	}
	else
	{
		add = malloc(len + 1);
	}
	ft_active_all_1(conv, stock, len, i);
	
}

void 	ft_active(char *stock, char *conv)
{
	int		i;
	char 	*number;
	int		count;

	i = ft_strlen(conv);
	number = NULL;
	count = 0;
	i--;
	if (strchr(conv, '.') && conv[0] == '0')
		conv = ft_delete_zero(conv);
	while (i >= 0)
	{
		if (ft_isdigit(conv[i]))
		{
			if (number == NULL)
			{
				number = malloc(strlen(conv) + 1);
			}
			number[count] = conv[i];	
			count++;

			if (i == 0 && conv[i] != '0')
			{
				count = 0;	
				number = ft_strrev(number);
				ft_active_all(conv, &stock, &number, i);	
				conv[count] = '\0';
			}
		}
		if (conv[i] == '-' && number)
		{
			count = 0;
			number = ft_strrev(number);
			ft_active_all(conv, &stock, &number, i);
		}
		if (conv[i] == '.')
		{
			if (( number == NULL || atoi(number) == 0 )&& atoi(stock) == 0)
			{
				if (number == NULL)
				{
					number = malloc(1);
					number[0] = '0';
					number[1] = '\0';
				}
				count = 0;
				ft_active_all(conv, &stock, &number, i);
			}
			else if(number)
			{
				count = 0;
				number = ft_strrev(number);
				ft_active_all(conv, &stock, &number, i);
			}
		}
		if (conv[i] == '0' && number && i == 0)
		{			
		count = 0;
		number = ft_strrev(number);
		number = ft_delete_zero(number);
		ft_active_all(conv, &stock, &number, i);		
		}
			
		i--;
	}

	ft_putstr_write(stock);
}
