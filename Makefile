NAME	=	push_swap
HEADER	=	push_swap.h
OBG		=	${SRC:.c=.o}
SRC_UTL =	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_isdigit.c ft_atoi.c print_comand.c
SRC_COM = 	s.c p.c

SRC		=	$(addprefix ./utils/, ${SRC_UTL}) $(addprefix ./comand/, ${SRC_COM})  main.c

BONUS_OBJ = ${BONUS_SRC:.c=.o}
FLAGS	= -Wall -Wextra -Werror
RM = rm -rf



.c.o:
			gcc ${FLAGS} -I./ -c $< -o ${<:.c=.o}

all:		${OBG} 
			gcc ${FLAGS} -o push_swap  -I./ $(OBG)
clean:
			rm -rf ${OBG} ${BONUS_OBJ}
fclean: 	clean
			rm -rf ${NAME}

re:			fclean all

$(NAME):	all
		
.PHONY: all clean fclean re ${NAME}
