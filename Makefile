# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 17:01:24 by asaba        #+#   ##    ##    #+#        #
#    Updated: 2019/02/04 16:39:42 by asaba       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol

CC = gcc

SRC = srcs/main.c srcs/input.c srcs/fractal.c srcs/display.c
SRC += srcs/newimg.c srcs/error.c srcs/session.c srcs/get_input.c

OBJ = $(SRC:.c=.o)

INC_HDR = -I./includes -I./libft/includes -I./minilibx_macos

INC_LIB = 	-L./libft -lft -L./minilibx_macos -lmlx \
			-framework OpenGL -framework AppKit 

CFLAGS = -Werror -Wextra -Wall $(INC_HDR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos
	@printf "\033[33mFRACTOL\033[0m\t\t\t\t\t\t\t\t[\033[92mCOMPILED\033[39m]\n"
	@$(CC) $(CFLAGS) $(INC_LIB) $(SRC) -o $(NAME)

%.o: %.c includes/fractol.h
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@cd libft && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && $(MAKE) fclean

re: fclean all
