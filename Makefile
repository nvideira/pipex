# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 02:51:23 by nvideira          #+#    #+#              #
#    Updated: 2022/05/15 03:58:42 by nvideira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=		pipex.c

OBJS=		$(SRCS:.c=.o)

NAME=		pipex

LIBFT=		Libft/libft.a
LIBFT_DIR=	libft

CC=			gcc
CFLAGS=		-Wall -Wextra -Werror

.all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "\033[93mPiping.  \033[0m"
	@sleep 0.8
	@echo "\033[93mPiping.. \033[0m"
	@sleep 0.8
	@echo "\033[93mPiping...\033[0m"
	@sleep 0.8
	@echo "\033[92mReady to pipe stuff\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(LIBFT):
	@echo "\033[93mMaking Libft\033[0m"
	@make -s -C $(LIBFT_DIR)
	@echo "\033[92mLibft compiled!\033[0m"
