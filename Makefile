NAME	=   push_swap
HEADER  =   push_swap.h

SRC_UTL = $(shell ls ./utils/*.c) 

SRC_COM	=   $(shell ls ./comand/*.c) 

SRCS		=  $(SRC_UTL)  $(SRC_COM) main.c

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

CC		=   gcc

OBG		=	$(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	${OBG} $(HEADER)
			$(CC) -o $(NAME) ${OBG}

%.o: 		%.c	
			$(CC) $(CFLAGS) -I./ -c $< -o $@
 
clean:
			$(RM) ${OBG}

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

test:		
			make -s && make -s  clean && ./$(NAME) 1 2 3 4 

.PHONY: clean fclean re all
