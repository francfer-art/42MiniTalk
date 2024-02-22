# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 16:07:26 by mulken            #+#    #+#              #
#    Updated: 2024/02/22 18:00:52 by francfer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME_BONUS = minitalk_bonus
SRCDIR = src
SRCDIR_BONUS = src_bonus
INCDIR = include

SRCLIENT = $(SRCDIR)/client.c
OBJSCLIENT = $(SRCLIENT:.c=.o)
SRCLIENT_BONUS = $(SRCDIR_BONUS)/client_bonus.c
OBJSCLIENT_BONUS = $(SRCLIENT_BONUS:.c=.o)

SRCSERVER = $(SRCDIR)/server.c
OBJSERVER = $(SRCSERVER:.c=.o)
SRCSERVER_BONUS = $(SRCDIR_BONUS)/server_bonus.c
OBJSERVER_BONUS = $(SRCSERVER_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)
LIBFTPRINTF_DIR = ./Printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJSERVER) $(OBJSCLIENT)
	@make -C $(LIBFTPRINTF_DIR)
	gcc -o server $(OBJSERVER) $(CFLAGS) $(LIBFTPRINTF)
	gcc -o client $(OBJSCLIENT) $(CFLAGS) $(LIBFTPRINTF)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(OBJSERVER_BONUS) $(OBJSCLIENT_BONUS)
	@make -C $(LIBFTPRINTF_DIR)
	gcc -o server_bonus $(OBJSERVER_BONUS) $(CFLAGS) $(LIBFTPRINTF)
	gcc -o client_bonus $(OBJSCLIENT_BONUS) $(CFLAGS) $(LIBFTPRINTF)

$(SRCDIR)/%.o: $(SRCDIR_BONUS)/%.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJSERVER) $(OBJSCLIENT)
	@rm -f $(OBJSERVER_BONUS) $(OBJSCLIENT_BONUS)
	@make -C $(LIBFTPRINTF_DIR) clean
	@echo "Cleaning Objs!"

fclean: clean
	@rm -f server client client_bonus server_bonus
	@make -C $(LIBFTPRINTF_DIR) fclean
	@echo "Fcleaning All!"

norm: 
	norminette
	
re: fclean all

.PHONY: all clean fclean re norm
