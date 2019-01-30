# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 17:01:24 by asaba        #+#   ##    ##    #+#        #
#    Updated: 2019/01/03 11:28:29 by asaba       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

CC = gcc

SRC =	srcs/ft_atoi.c srcs/ft_bzero.c srcs/ft_isalnum.c srcs/ft_isalpha.c
SRC +=	srcs/ft_isascii.c srcs/ft_isdigit.c srcs/ft_isprint.c srcs/ft_itoa.c
SRC +=	srcs/ft_memalloc.c srcs/ft_memccpy.c srcs/ft_memchr.c srcs/ft_memcmp.c
SRC +=	srcs/ft_memcpy.c srcs/ft_memdel.c srcs/ft_memmove.c srcs/ft_memset.c
SRC +=	srcs/ft_putchar.c srcs/ft_putchar_fd.c srcs/ft_putendl.c srcs/ft_putendl_fd.c
SRC +=	srcs/ft_putnbr.c srcs/ft_putnbr_fd.c srcs/ft_putstr.c srcs/ft_putstr_fd.c
SRC +=	srcs/ft_strcat.c srcs/ft_strchr.c srcs/ft_strclr.c srcs/ft_strcmp.c
SRC +=	srcs/ft_strcpy.c srcs/ft_strdel.c srcs/ft_strdup.c srcs/ft_strequ.c
SRC +=	srcs/ft_striter.c srcs/ft_striteri.c srcs/ft_strjoin.c srcs/ft_strlcat.c
SRC +=	srcs/ft_strlen.c srcs/ft_strmap.c srcs/ft_strmapi.c srcs/ft_strncat.c
SRC +=	srcs/ft_strncmp.c srcs/ft_strncpy.c srcs/ft_strnequ.c srcs/ft_strnew.c
SRC +=	srcs/ft_strnstr.c srcs/ft_strrchr.c srcs/ft_strrev.c srcs/ft_strsplit.c
SRC +=	srcs/ft_strstr.c srcs/ft_strsub.c srcs/ft_strtrim.c srcs/ft_tolower.c
SRC +=	srcs/ft_toupper.c srcs/ft_lstnew.c srcs/ft_lstmap.c srcs/ft_lstiter.c
SRC +=	srcs/ft_lstdelone.c srcs/ft_lstdel.c srcs/ft_lstadd.c srcs/ft_iswhite.c
SRC +=	srcs/ft_recursive_power.c srcs/ft_range.c srcs/ft_sqrt.c
SRC	+=	srcs/get_next_line.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Werror -Wextra -Wall -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $?
	@printf "\033[33mLIBFT\033[0m\t\t\t\t\t\t\t\t[\033[92mCOMPILED\033[39m]\n"

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
