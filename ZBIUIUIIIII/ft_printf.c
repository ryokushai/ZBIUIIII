/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:45:57 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/20 08:58:26 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_printf;
/*
void	ft_while(char **str, char **conv, int *num, int *count)
{
	int i;
			
	i = 0;
	*count = 0;
		while (**str != '%')
		{
			ft_putchar(**str);
			(*str) += 1;
			if (**str == '\0')
			{
				return ;
			}
		}
		(*str) += 1;
		if (**str == '\0')
			return ;
		*conv = ft_conditions(*str);	
		*num = strlen(*conv);
		(*str) = (*str) + (*num);
		while ((*conv)[i])
		{
			if ((*conv)[i] == '*')
				(*count)+= 1;
			i++;
		}

}
*/
void	ft_free(char **stock, char **conv)
{
		*conv = NULL;
		*stock = NULL;
		free(*conv);
		free(*stock);
}

void	ft_condition_2(char *stock, char *conv, char *str, va_list arg)
{
		if (*str == 'c')
		{
			stock = ft_char(va_arg(arg, int));
			ft_active_char(stock, conv);
		}	
		if (*str == 's')
		{
			stock = va_arg(arg, char *);
			ft_active_string(stock,conv);
		}
		if (*str == 'd' || *str == 'i')
		{
			stock = ft_itoa(va_arg(arg, int));
			ft_active(stock, conv);
		}
}
void	ft_condition_1(char *stock, char *conv,char *str, va_list arg)
{
		if (*str == 'u')
		{
			stock = ft_itoa_2(va_arg(arg, unsigned int));
			ft_active(stock,conv);
		}
		if (*str == 'x')
		{
			stock = ft_itohexa(va_arg(arg, unsigned int));
			ft_active(stock, conv);
		}
		if (*str == 'X')
		{
			stock = ft_itohexa2(va_arg(arg, unsigned int));
			ft_active(stock, conv);
		}
		if (*str == 'p')
		{
			stock = ft_adress(va_arg(arg, unsigned long long));
			ft_active(stock, conv);
		}
}
void	ft_active_active(char *str, char *stock, char *conv, va_list arg)
{
	if (*str == '%')
		{
			stock = malloc(2);
			stock[0] = '%';
			stock[1] = '\0';
			ft_active_pour(stock,conv);
		}
		if (*str == 'c' || *str == 's' || *str == 'd' || *str == 'i')
		{
			ft_condition_2(stock, conv, str, arg);
		}

		if (*str == 'u' || *str == 'x' || *str == 'X' || *str == 'p')
		{
			ft_condition_1(stock, conv,str ,arg);
		}
}

char	**ft_etoile(va_list arg, int *count, int *len)
{
	char	**etoile;
	int		e;

	e = 0;
	etoile = malloc(sizeof(char *) * 3);
	while (*count)
	{
		etoile[e] = ft_itoa(va_arg(arg, int));
		*len = strlen(etoile[e]) + (*len);
		e++;
		(*count) -= 1;
	}
	etoile[e] = 0;
	return etoile;
}
char	*ft_work_etoile(int num, int len, char *conv, char **etoile)
{
	char	*conv2;
	int		i;
	int		e;
	int		z;
	int		j;

	e = 0;
	i = 0;
	z = 0;
	j = 0;
		conv2 = malloc(num + len + 1);
		while (conv[i])
		{
			z = 0;
			while (conv[i] != '*' && conv[i])
				conv2[j++] = conv[i++];
			while (etoile[e] && etoile[e][z])
				conv2[j++] = etoile[e][z++];
			e++;
			if (conv[i])
				i++;
		}
		conv2[j] = '\0';
		return conv2;
}


int	 ft_work(va_list arg, char *str)
{

	char	*conv;
	int 	num;
	char	*stock;
	int 	i;
	int 	count;
	char	**etoile;
	int		len;

	len = 0;
	while (*str != '\0')
	{
		//ft_while(&str, &conv, &num, &count);
		
		i = 0;
		count = 0;
		while (*str != '%')
		{
			ft_putchar(*str);
			str++;
			if (*str == '\0')
			{
				return 0;
			}
		}
		str++;
		if (*str == '\0')
			return 0;
		conv = ft_conditions(str);	
		num = strlen(conv);
		str = str + num;
		while (conv[i])
		{
			if (conv[i] == '*')
				count++;
			i++;
		}
		
		etoile = ft_etoile(arg, &count, &len);
		conv = ft_work_etoile(num,  len,  conv, etoile);
		ft_active_active(str, stock, conv, arg);
		str++;
		ft_free(&conv , &stock);

	}
	return 0;
}

int		ft_printf(char *format, ...)
{
	va_list	arg;
	char *str;

	va_start(arg, format);
	str = format;
	ft_work(arg, str);
	va_end(arg);
	return g_printf;
}