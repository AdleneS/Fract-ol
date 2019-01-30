# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 17:01:24 by asaba        #+#   ##    ##    #+#        #
#    Updated: 2019/01/24 11:14:56 by asaba       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

CC = gcc

SRC = srcs/main.c srcs/bresenham.c srcs/parse.c srcs/algo.c srcs/input.c
SRC += srcs/newimg.c srcs/color.c srcs/error.c srcs/hud.c srcs/useful.c

OBJ = $(SRC:.c=.o)

INC_HDR = -I./includes -I./libft/includes -I./minilibx_macos

INC_LIB = 	-L./libft -lft -L./minilibx_macos -lmlx \
			-framework OpenGL -framework AppKit 

CFLAGS = -Werror -Wextra -Wall $(INC_HDR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos
	@printf "\033[33mFDF\033[0m\t\t\t\t\t\t\t\t[\033[92mCOMPILED\033[39m]\n"
	@$(CC) $(CFLAGS) $(INC_LIB) $(SRC) -o $(NAME)

%.o: %.c includes/fdf.h
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@cd libft && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && $(MAKE) fclean

re: fclean all
