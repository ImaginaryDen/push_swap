NAME	=   push_swap
HEADER  =   push_swap.h
NAME_BONUS	=   checker

SRC_UTL = $(shell ls ./utils/*.c) 
SRC_COM	=   $(shell ls ./comand/*.c) 
SRC_HELP = $(shell ls ./sort/*.c)

SRCS		=	$(SRC_UTL)  $(SRC_COM) $(SRC_HELP) push_swap.c
SRCS_BUNUS 	=	$(SRC_UTL)  $(SRC_COM) $(SRC_HELP) checker.c

OBG		=	$(SRCS:%.c=%.o)
OBG_BONUS		=	$(SRCS_BUNUS:%.c=%.o)

CFLAGS	= -Wall -Wextra -Werror 
RM		= rm -rf
CC		= gcc

ARG		=	$(shell ruby -e "puts (1..500).to_a.shuffle.join(' ')")

all:			$(NAME) $(NAME_BONUS)

$(NAME):		${OBG} $(HEADER)
				$(CC) $(CFLAGS)  -o $(NAME) ${OBG}

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	${OBG_BONUS} $(HEADER)
				$(CC) $(CFLAGS) -o $(NAME_BONUS) ${OBG_BONUS}

%.o: 			%.c	
				$(CC) $(CFLAGS) -I./ -c $< -o $@

clean:
				$(RM) ${OBG} ${OBG_BONUS}

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

test:
				touch arg.txt
				echo "$(ARG)" > arg.txt
				make -s && ./push_swap $(shell cat arg.txt) | ./checker $(shell cat arg.txt)

.PHONY: clean fclean re all bonus
