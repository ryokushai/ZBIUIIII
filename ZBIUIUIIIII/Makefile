# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haboussi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 17:38:33 by haboussi          #+#    #+#              #
#    Updated: 2019/12/13 17:38:34 by haboussi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


G = gcc -Wall -Wextra -Werror
SRC = ft_active.c ft_active_string.c ft_check_zero.c ft_adress.c ft_adress2.c  ft_null.c ft_conditions.c ft_active_char.c ft_char.c ft_itohexa3.c ft_delete_zero.c ft_itoa_2.c ft_flags.c ft_isdigit.c ft_itoa.c ft_itohexa.c ft_itohexa2.c ft_precision.c ft_printf.c ft_utils.c ft_trim.c ft_strdup.c


O = $(SRC:.c=.o)
NAME = libftprintf.a
OB = $(BNS:.c=.o)
all: $(NAME)
$(NAME):
	$(G) -c $(SRC)
	ar rc $(NAME) $(O)
	ranlib $(NAME)
	@echo $(NAME) is created
bonus:
	$(G) -c $(BNS)
	ar rs $(NAME) $(OB)
clean:
	rm -f $(O) $(OB)
fclean: clean
	rm -f $(NAME)
re: fclean all