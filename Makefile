NAME	=   push_swap
HEADER  =   push_swap.h

SRC_UTL = $(shell ls ./utils/*.c) 

SRC_COM	=   $(shell ls ./comand/*.c) 

SRC_HELP = $(shell ls ./sort/*.c)

SRCS		=  $(SRC_UTL)  $(SRC_COM) $(SRC_HELP) $(shell ls ./*.c) 

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

CC		=   gcc

OBG		=	$(SRCS:%.c=%.o)

ARG		=	$(shell ruby -e "puts (1..100).to_a.shuffle.join(' ')")

ARG_STATIC = $(shell cat arg.txt)

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
			make -s && ./push_swap $(ARG)


.PHONY: clean fclean re all
