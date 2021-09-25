#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define PRINT_ALL 0

enum e_game_rules
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_stack
{
	int				item;
	int				order;
	int				flag;
	struct s_stack	*next;
}				t_stack;

typedef struct s_sort_info
{
	int		size;
	int		mid;
	int		max;
	int		next;
	int		flag;
	t_stack	**a;
	t_stack	*b;
	t_stack	**command;
}				t_sort_info;

void	ft_lstadd_back(t_stack	**lst, t_stack	*new);
void	ft_lstadd_front(t_stack	**lst, t_stack	*new);
void	ft_lstclear(t_stack	**lst);
void	ft_lstiter(t_stack	*lst, void (*f)(int));
t_stack	*ft_lstlast(t_stack	*last);
t_stack	*ft_lstmap(t_stack	*lst, int (*f)(int));
t_stack	*ft_lstnew(int item);
int		ft_lstsize(t_stack	*lst);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		sa(t_stack **a, t_stack **b);
int		sb(t_stack **a, t_stack **b);
int		ss(t_stack **a, t_stack **b);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		ra(t_stack **a, t_stack **b);
int		rb(t_stack **a, t_stack **b);
int		rr(t_stack **a, t_stack **b);
int		rra(t_stack **a, t_stack **b);
int		rrb(t_stack **a, t_stack **b);
int		rrr(t_stack **a, t_stack **b);
void	ft_print_stack(t_stack *a, t_stack *b);
size_t	ft_strlen(const char *s);
int		ft_check(t_stack **a, t_stack *com);
void	ft_sort(t_stack *stack);
void	ft_sort_stack(t_stack **a, t_stack **comands, int magic_num);
void	ft_command_cheker(t_stack *commands);
int		check_first(t_stack *stack, int next);
int		check_second(t_stack *stack, int next);
int		check_last(t_sort_info	*sort_info);
int		check_two_first(t_sort_info *sort_info);
int		check_next(t_sort_info *info, int flag);
int		less(t_stack *a, int b);
int		larger(t_stack *a, int b);
void	div_stack(t_sort_info *s_i, t_stack **out,
			int (*compare)(t_stack *, int));
void	rev_stack(t_sort_info *info, int order);
int		ft_is_sort(t_stack *a, t_stack *b);
void	mini_sort(t_stack **a, t_stack **commands);
void	print_line_stack(t_stack *a, t_stack *b);
t_stack	*ft_lstcopy(t_stack *stack);
int		check_arg(char *arg, t_stack *a, int *num);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *destination, int c, size_t n);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		check_first(t_stack *stack, int next);
int		check_second(t_stack *stack, int next);
int		check_last(t_sort_info	*info);
int		check_two_first(t_sort_info *info);
void	push_next(t_sort_info *inf, int flag);
int		exit_error(t_stack **a, t_stack **b, int flag);
char	**ft_split(char const *s, char c);
size_t	get_size_str(char **str);
void	print_commands(t_stack *commands);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		pars_arg(char **argv, int argc, t_stack **stack);
void	ft_free_dabl_arr(char **strs);

#endif
