#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

#define TYPE_OUTPUT 2

typedef struct	s_stack
{
	int				item;
	struct s_stack	*next;
}				t_stack;

void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack  **lst, t_stack  *new);
void		ft_lstclear(t_stack  **lst);
void		ft_lstiter(t_stack  *lst, void (*f)(int));
t_stack 	*ft_lstlast(t_stack  *last);
t_stack 	*ft_lstmap(t_stack  *lst, int (*f)(int));
t_stack 	*ft_lstnew(int item);
int			ft_lstsize(t_stack  *lst);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		sa(t_stack **a, t_stack **b);
void		sb(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		ra(t_stack **a, t_stack **b);
void		rb(t_stack **a, t_stack **b);
void		rra(t_stack **a, t_stack **b);
void		rrb(t_stack **a, t_stack **b);
void		print_comand(char *head, t_stack *a, t_stack *b);

#endif
