# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 15:00:56 by knovytsk          #+#    #+#              #
#    Updated: 2018/01/04 17:30:18 by knovytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = srcs/main.c srcs/get_file_data.c srcs/make_wireframe.c \
		srcs/rotation.c srcs/draw.c srcs/key_events.c \
		srcs/image.c srcs/mouse_events.c srcs/reset.c srcs/instruction.c
LIBFT = -C libft
CC = cc -Wall -Wextra -Werror 
FLAGS = -lmlx -framework OpenGL -framework AppKit
OBJECTS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT): 
	@make $(LIBFT) 
	@echo "\033[36mLibft is compiled\033[0m" 

%.o: %.c
	@$(CC) -c -o $@ $<

$(NAME): $(OBJECTS)
	@$(CC) -o $(NAME) $(OBJECTS) libft/libft.a $(FLAGS)
	@echo "\033[32mTHE PROGRAM IS READY\033[0m"

clean: 
	@make clean -C libft
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f libft/libft.a
	@/bin/rm -f $(NAME)
	@echo "\033[36mCleaned\033[0m"

re: fclean all

.PHONY: clean fclean re all
