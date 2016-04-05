# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/05 16:20:26 by nmougino          #+#    #+#              #
#    Updated: 2016/04/05 20:35:18 by nmougino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compilator
CC =		clang
CFLAGS =	-Wall -Wextra -Werror
ADDFLAGS =	-framework OpenGL -framework Appkit

#	Binary
NAME =		libdraw.a

#	Default rule
DEFRULE =	glulib

#	Dossiers utiles
SRCDIR =	srcs
INCDIR =	includes
LIBDIR =	libs
OBJDIR =	objs

#	Liste des sources
SRC =		draw_clear_img.c \
			draw_curcolor.c \
			draw_line.c \
			draw_line_rgb.c \
			draw_new_img.c \
			draw_new_line.c \
			draw_pixel.c \
			draw_pixel_rgb.c \
			draw_square.c
LIB =
LIBA =
OBJ =		$(SRC:.c=.o)

#	Prefixes
LLIBS =		$(addprefix -L$(LIBDIR) -l, $(LIB))
LIBAP =		$(addprefix $(LIBDIR)/, $(LIBA))
OBJP =		$(addprefix $(OBJDIR)/, $(OBJ))

#	Couleurs
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

.PHONY = all glu $(NAME) $(OBJDIR) clean fclean re

# #
#	RULES
#

#	Main rules
default:
	@echo "\n\n$(GRA)$(GRE)			-*-  MAKEFILE  -*- \n$(BLU)  @nmougino$(DEF)\n"
	@echo "$(GRA)  DEFAULT RULE EXECUTION  :::  rule $(DEFRULE)$(DEF)"
	@make $(DEFRULE)
	@echo

all: $(OBJDIR) $(NAME)

alllib: $(OBJDIR) librarize

glu: re
	@make clean

re: fclean all

glulib: relib
	@make clean

relib: fclean alllib

$(OBJDIR):
	@echo "\n$(GRA)$(CYA)@ ++ Objects compilation$(DEF)"
	mkdir -p $(OBJDIR)

#	Lib rules
$(LIB):
	make -C lib$@/
	mv lib$@/lib$@.a $(LIBDIR)

librarize: $(OBJP)
	@echo "$(GRA)$(GRE)@ ++ $(NAME) LIBRARIZATION$(DEF)"
	ar rc $(NAME) $^

#	Compilation rules
$(NAME): $(OBJP)
	@echo "$(GRA)$(GRE)@ ++ $(NAME) COMPILATION$(DEF)"
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCDIR) $(LLIBS) $(ADDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCDIR) $(LIBAP)

#	MrProper's legacy
clean:
	@echo "\n$(RED)@ Objects deletion$(DEF)"
	rm -rf $(OBJDIR)

fclean: clean
	@echo "\n$(RED)@ Bin deletion$(DEF)"
	rm -f $(NAME)
