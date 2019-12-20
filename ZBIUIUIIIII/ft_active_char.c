/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:31:30 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/16 19:31:31 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char 	*add;
int 	len_number;
int		len_stock;

void	ft_active_all_1_char(char *conv, char **stock, int len, int i)
{
	if (conv[i] == '0')
	{
		memset(add, '0', len);
		*stock= ft_stock(add, *stock);
	}
	
	else if (ft_isdigit(conv[i]))
	{
		memset(add, ' ', len);
		add[len] = '\0';
		ft_putstr_write(add);
		ft_putchar(**stock);
	}
	if (conv[i] == '-')
	{
		ft_putchar(**stock);
		memset(add, ' ', len);
		add[len] = '\0';
		ft_putstr_write(add);
	}
	if (conv[i] == '.')
	{
		ft_putchar(**stock);
	}
}

void	ft_active_all_char(char	*conv, char **stock,char **number, int i)
{
	int		len;

	if (**stock == '\0')
		len = atoi(*number) - 1;
	else
		len = atoi(*number) - ft_strlen(*stock);
    len_number = atoi(*number);
	len_stock = ft_strlen(*stock);
	free(*number);
	*number = NULL;
	if (len <= 0 )
	{
		ft_putstr_write(*stock);
		return ;
	}	
	add = malloc(len + 1);
	ft_active_all_1_char(conv, stock, len, i);
}

void	ft_active_char(char *stock, char *conv)
{
	int		i;
	char 	*number;
	int		count;
	int 	checkpoint;
	
	i = ft_strlen(conv);
	number = NULL;
	count = 0;
	checkpoint = 0;
	i--;
	if (strchr(conv, '.') && conv[0] == '0')
		conv = ft_delete_zero(conv);
	while (i >= 0)
	{
		if (ft_isdigit(conv[i]))
		{
			
			checkpoint = 1;
			if (number == NULL)
			{
				number = malloc(strlen(conv) + 1);
			}
			number[count] = conv[i];	
			count++;
		
			if (i == 0 && conv[i] != '0')
			{
				number[count] = '\0';
				count = 0;	
				number = ft_strrev(number);
				ft_active_all_char(conv, &stock, &number, i);	
			}
		}
		if (conv[i] == '-' && number)
		{
			number[count] = '\0';
			checkpoint = 1;
			count = 0;
			number = ft_strrev(number);
			ft_active_all_char(conv, &stock, &number, i);
		}
		if (conv[i] == '.')
		{
			checkpoint = 0;
		}
		if (conv[i] == '0' && number && i == 0)
		{
			count = 0;
			number = ft_strrev(number);
			ft_active_all_char(conv, &stock, &number, i);
			checkpoint = 1;
		}
		i--;
	}	
	if (checkpoint == 0)
	{
		ft_putchar(*stock);
	}
}	