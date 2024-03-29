# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 02:51:23 by nvideira          #+#    #+#              #
#    Updated: 2022/06/06 23:11:50 by nvideira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=		bonus.c\
			pip_utils.c

OBJS=		$(SRCS:.c=.o)

NAME=		pipex

LIBFT=		Libft/libft.a
LIBFT_DIR=	libft

INCLUDES	= -I Libft -I Libft/get_next_line -I ft_printf -I .

PRINTF=		ft_printf/libftprintf.a
PRINTF_DIR=	ft_printf

CC=			gcc
CFLAGS=		-Wall -Wextra -Werror

.c.o:
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@printf "\033[93mPiping.  \033[0m \r"
	@sleep 0.5
	@printf "\033[93mPiping.. \033[0m \r"
	@sleep 0.5
	@printf "\033[93mPiping...\033[0m"
	@sleep 0.5
	@printf "\033[92\nmReady to pipe stuff\n\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)


$(LIBFT):
	@echo "\033[93mMaking Libft\033[0m"
	@make -s -C $(LIBFT_DIR)
	@echo "\033[92mLibft compiled!\033[0m"

$(PRINTF):
	@make -s -C $(PRINTF_DIR)
	
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes\
		./$(NAME) cat cat wc
clean:
	@rm -f $(OBJS)
	@make -s clean -C $(LIBFT_DIR)
	@make -s clean -C $(PRINTF_DIR)

fclean:	clean
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR)
	@make -s fclean -C $(PRINTF_DIR)

re:	fclean all

.PHONY:	all clean fclean re
