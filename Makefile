##
## Makefile for Makefile in /home/cosson_v
## 
## Made by Vincent Cosson
## Login   <cosson_v@epitech.net>
## 
## Started on  Mon Jan 11 11:54:53 2016 Vincent Cosson
## Last update Fri Aug 12 14:31:48 2016 Reever Valerus
##

CC	=	gcc

RM	=	rm -f

NAME	=	sudoki-bi

SRCS	= 	basics.c \
		retrieve_map.c \
		get_next_line.c \
		tab_int.c \
		check_line.c \
		sudoki.c \

CFLAGS += -Wextra -Wall -Werror
CFLAGS += -I./include
CFLAGS += -ansi -pedantic

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) -g3

clean:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
