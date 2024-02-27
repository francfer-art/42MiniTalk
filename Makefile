# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 12:14:46 by francfer          #+#    #+#              #
#    Updated: 2024/02/27 15:09:51 by francfer         ###   ########.fr        #
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

bonus: $(NAME_BONUS)

$(NAME): server client

server: $(OBJSERVER)
	@make -C $(LIBFTPRINTF_DIR)
	gcc -o $@ $(OBJSERVER) $(CFLAGS) $(LIBFTPRINTF)

client: $(OBJSCLIENT)
	@make -C $(LIBFTPRINTF_DIR)
	gcc -o $@ $(OBJSCLIENT) $(CFLAGS) $(LIBFTPRINTF)

$(OBJSERVER): $(SRCDIR)/%.o: $(SRCDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@

$(OBJSCLIENT): $(SRCDIR)/%.o: $(SRCDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME_BONUS): server_bonus client_bonus

server_bonus: $(OBJSERVER_BONUS)
	@make -C $(LIBFTPRINTF_DIR)
	gcc -o $@ $(OBJSERVER_BONUS) $(CFLAGS) $(LIBFTPRINTF)

client_bonus: $(OBJSCLIENT_BONUS)
	@make -C $(LIBFTPRINTF_DIR)
	gcc -o $@ $(OBJSCLIENT_BONUS) $(CFLAGS) $(LIBFTPRINTF)

$(OBJSERVER_BONUS): $(SRCDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c
	gcc $(CFLAGS) -c $< -o $@

$(OBJSCLIENT_BONUS): $(SRCDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c
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
