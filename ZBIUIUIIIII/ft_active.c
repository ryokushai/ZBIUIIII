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
int count;

void	ft_while_part_three_int(char *conv, char **stock, char **number, int i)
{
			if (conv[i + 1] == '-' && **stock == '0')
			{
				**stock = '0';
			}
			else
			{
				if (*number)
				{
					(*number)[count] = '\0';
				}
				if (( *number == NULL || atoi(*number) == 0 ) && ft_check_zero(*stock))
				{
					if (*number == NULL)
					{
						*number = malloc(2);
						(*number)[0] = '0';
						(*number)[1] = '\0';
					}
					count = 0;
					ft_active_all(conv, stock, number, i);
				}
				else if(*number)
				{
					(*number)[count] = '\0';
					count = 0;
					*number = ft_strrev(*number);
					ft_active_all(conv, stock, number, i);
				}
			}
}

void	ft_while_part_two_int(char *conv, char **stock, char **number, int i)
{
		if (conv[i] == '-' && *number) 
		{
			(*number)[count] = '\0';
			count = 0;
			if(ft_skip_minus(conv,i))
			{
			*number = ft_strrev(*number);
			ft_active_all(conv, stock, number, i);
			}
			else
			{
				*number = NULL;
				free(*number);	
			}
		}
}

void	ft_while_part_one_int(char *conv, char **stock, char **number, int i)
{
		if (conv[i] == '0' && *number && i == 0)
		{
			(*number)[count] = '\0';			
			count = 0;
			*number = ft_strrev(*number);
			ft_active_all(conv, stock, number, i);		
		}	
		else if (ft_isdigit(conv[i]))
		{
			if (*number == NULL)
			{
				*number = malloc(strlen(conv) + 1);
			}
			(*number)[count] = conv[i];	
			count++;
			if (i == 0 && conv[i] != '0')
			{
				(*number)[count] = '\0';
				count = 0;	
				*number = ft_strrev(*number);
				ft_active_all(conv, stock, number, i);	
			}
		}
}

void	ft_active_all_1(char *conv, char **stock, int len, int i)
{
	add = malloc(len + 1);
	if (conv[i] == '0')
	{
		if (*stock[0] == '-')
		{
			*stock = ft_delete_minus(*stock);
			memset(add, '0', len );
			add[len] = '\0';
			add = ft_stock("-", add);
			*stock = ft_stock(add, *stock);
		}
		else
		{
			memset(add, '0', len);
			add[len] = '\0';
			*stock = ft_stock(add, *stock);
		}
	}
	else if (ft_isdigit(conv[i]))
	{
		
		memset(add, ' ', len);
		add[len] = '\0';
		*stock = ft_stock(add, *stock);
	}
	if (conv[i] == '-')
	{
		memset(add, ' ', len);
		add[len] = '\0';
		*stock = ft_stock(*stock, add);
	
	}
	if (conv[i] == '.')
	{
		add = malloc(len + 2);
		if (*stock[0] == '-')
		{
			len++;
			*stock = ft_delete_minus(*stock);
			memset(add, '0', len);
			add[len] = '\0';
			add = ft_stock("-", add);
			*stock = ft_stock(add, *stock);

		}
		else
		{
			memset(add, '0', len);
			add[len] = '\0';
			*stock = ft_stock(add, *stock);
		}
	}
}

void	ft_active_all(char	*conv, char **stock,char **number, int i)
{
	int		len;
	int 	j;

	//char    *add;
	
	if (atoi(*number) == 0 && atoi(*stock) == 0 && (j = ft_check_zero(*stock)))
	{
		if (j == 2)
		{
			(*stock)[2] = '\0';
		}
		else
		{
			*stock = "";
		}
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

	char 	*xtr;
	i = ft_strlen(conv);
	number = NULL;
	count = 0;
	i--;
	xtr = strchr(conv,'.');
	if ((xtr && conv[0] == '0' && xtr[1] != '-') || (conv[0] == '0' && conv[1] == '-'))
		conv = ft_delete_zero(conv);
	while (i >= 0)
	{
		ft_while_part_one_int(conv, &stock, &number, i);
		ft_while_part_two_int(conv, &stock, &number,i);
		if (conv[i] == '.')
		{
			ft_while_part_three_int(conv, &stock, &number,i);
		}
		i--;
	}
	ft_putstr_write(stock);
}