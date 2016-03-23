# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 01:02:57 by nmougino          #+#    #+#              #
#    Updated: 2016/03/23 18:05:05 by nmougino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COULEURS
#

DEF		= \033[0m
GRA		= \033[1m
SOU		= \033[4m
BLI		= \033[5m
BLA		= \033[30m
RED		= \033[31m
GRE		= \033[32m
YEL		= \033[33m
BLU		= \033[34m
PUR		= \033[35m
CYA		= \033[36m
WHI		= \033[37m

SRC =	srcs
INC =	includes
LIB =	libs

MLXFLAGS = -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

glu: lib
	gcc $(CFLAGS) $(LIB)/*.a main.c libdraw.a -I$(INC) $(MLXFLAGS)

lib:
	gcc $(CFLAGS) -c $(SRC)/*.c main.c -I$(INC)
	ar rc libdraw.a *.o
	rm *.o

uti:
	gcc $(CFLAGS) $(LIB)/*.a main.c libdraw.a -I$(INC) $(MLXFLAGS)
