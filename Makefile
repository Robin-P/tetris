##
## Makefile for  in /home/robin/delivery/PSU_2016_tetris
## 
## Made by Robin Pronnier
## Login   <robin@epitech.net>
## 
## Started on  Fri Mar 10 14:46:18 2017 Robin Pronnier
## Last update Tue Mar 14 12:59:41 2017 benoit pingris
##

CC	=	gcc

NAME	=	tetris

SRC	=	./srcs/main.c \
		./srcs/set.c \
		./srcs/need.c \
		./srcs/perfect.c \
		./srcs/end_win.c \
		./srcs/end_win_2.c \
		./srcs/check.c \
		./srcs/turn.c \
		./srcs/free.c \
		./srcs/next.c \
		./srcs/game.c \
		./srcs/game_2.c \
		./srcs/game_3.c \
		./srcs/fall.c \
		./srcs/display.c \
		./srcs/set_game.c \
		./srcs/size.c \
		./srcs/error.c \
		./srcs/check_flags.c \
		./srcs/sort_name.c \
		./srcs/ptr_f_1.c \
		./srcs/ptr_f_2.c \
		./srcs/ptr_f_3.c \
		./srcs/debug.c \
		./srcs/debug_2.c \
		./srcs/get_next_line/get_next_line.c \
		./srcs/useful/str.c \
		./srcs/useful/str2.c \
		./srcs/useful/str3.c \
		./srcs/useful/blocking_read.c \
		./srcs/my_printf/my_printf.c \
		./srcs/my_printf/my_func1.c \
		./srcs/my_printf/my_func2.c \
		./srcs/my_printf/my_func3.c \
		./srcs/my_printf/my_func4.c \
		./srcs/my_printf/func_printf_1.c \
		./srcs/my_printf/func_printf_2.c \
		./srcs/my_printf/my_basics_funcs.c \
		./srcs/my_printf/my_basics_funcs_2.c \

CFLAGS +=	-I./includes

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lncurses

clean	:
		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

