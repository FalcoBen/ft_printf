# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenalla <fbenalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 04:46:26 by fbenalla          #+#    #+#              #
#    Updated: 2024/11/27 13:39:45 by fbenalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCF = ft_printf.c ft_printf_generate.c ft_itoa.c ft_strlen.c \
		ft_strdup.c ft_itoabase.c ft_uitoa.c ft_printf_extra.c 

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

RM = rm -f

PRINTFH = ft_printf.h

OBJC = $(SRCF:.c=.o)

all : $(NAME)

$(NAME) : $(OBJC)
	$(AR) $(NAME) $(OBJC)

%.o : %.c $(PRINTFH)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJC)

fclean : clean
	$(RM) $(NAME)

re : fclean all