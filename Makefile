NAME	=   push_swap
HEADER  =   push_swap.h

SRC_UTL = $(shell ls ./utils/*.c) 

SRC_COM	=   $(shell ls ./comand/*.c) 

SRCS		=  $(SRC_UTL)  $(SRC_COM) $(shell ls ./*.c) 

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
			make -s && make -s  clean && ./push_swap 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

.PHONY: clean fclean re all
