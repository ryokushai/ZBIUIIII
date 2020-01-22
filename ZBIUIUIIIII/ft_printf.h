/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboussi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:19:10 by haboussi          #+#    #+#             */
/*   Updated: 2019/12/20 08:19:02 by haboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#include <stdarg.h>


int		ft_skip_minus(char *conv, int i);
char	*ft_delete_point(char *conv);
void	ft_active_all_1_pour(char *conv, char **stock, int len, int i);
void	ft_active_all_pour(char	*conv, char **stock,char **number, int i);
char	*ft_flags(char *str);
void	ft_active_pour(char *stock, char *conv);
char    *ft_char(char s);
int    ft_check_zero(char *stock);
int 	ft_printf(char *format, ...);
void	ft_active_all_1_string(char *conv, char **stock, int len, int i);
void	ft_active_all_string(char	*conv, char **stock,char **number, int i);
void	ft_active_all_1_char(char *conv, char **stock, int len, int i);
char    *ft_null(char *stock);
void	ft_active_all_char(char	*conv, char **stock,char **number, int i);
void	ft_active_char(char *stock, char *conv);
int     ft_return_len_printf(int len);
char	*ft_stock_int_u(unsigned int  n, char *dest);
char	*ft_delete_zero(char *conv);
char	*ft_delete_minus(char *stock);
char	*ft_strdup(char *src);
char	*ft_adress(unsigned long long n);
char	*ft_itoa_2(unsigned int n);
char    *ft_trim(char *stock, int len_number);
void    ft_putstr_write(char *str);
void    ft_active(char *stock, char *conv);
void	ft_active_all(char	*conv, char **stock,char **number, int i);
void    ft_active_string(char *stock, char *conv);
int     ft_isdigit(int c);
char	*ft_width(char *str);
char	*ft_stock_int(int n, char *dest);
char	*ft_precision(char *str);		
char	*ft_substr(char *s, int start, int len);
void	ft_skip(char *str);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
int		ft_strlcpy(char *dst, char *src, int n);
void	ft_putchar(char c);
char	*ft_itoa(int n);
char	*ft_itohexa(unsigned int  n);
char	*ft_itohexa2(unsigned int  n);
char	*ft_itohexa3(unsigned long long  n);
int		ft_lenght(unsigned long long  n);
char	*ft_strrev(char *str);
char	*ft_stock(char *s1, char *s2);
char	*ft_adress(unsigned long long n);
char	*ft_conditions(char *str);
#endif
