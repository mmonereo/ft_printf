# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/16 15:24:17 by mmonereo          #+#    #+#              #
#    Updated: 2021/09/29 09:39:51 by mmonereo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

LIBFT			= libft

SRCS			=	ft_printf.c aux.c is_i.c is_s.c is_x.c \
					is_p.c is_u.c is_c.c is_perc.c flags.c conversion.c 

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror 

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar rcs $(NAME) $(OBJS)

%.o: 			%.c
				$(CC) $(CFLAGS) -c -o $@ $<

clean:
				@$(RM) $(OBJS)
				@make clean -C $(LIBFT) 

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re 