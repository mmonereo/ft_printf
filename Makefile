# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/16 15:24:17 by mmonereo          #+#    #+#              #
#    Updated: 2021/01/26 12:10:35 by mmonereo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

LIBFT			= libft

SRCS			=	ft_printf.c is_i.c is_s.c is_x.c \
					is_p.c is_u.c is_c.c is_perc.c mod.c 

OBJS			= $(SRCS:.c=.o)

C				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror 

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -C $(LIBFT)
				@cp libft/libft.a ./printf
				@ar rcs $(NAME) $(OBJS)

%.o: 			%.c
				$(CC) $(CFLAGS) -c -o $@ $<

clean:
				@$(RM) $(OBJS)
				@make clean -C $(LIBFT) 

fclean:			clean
				@$(RM) $(OBJS)
				@make fclean -C $(LIBFT) 

re:				fclean all

.PHONY:			all clean fclean re 