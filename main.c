#include "push_swap.h"

int exit_error(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	ft_putstr_fd("ERROR\n", 1);
	return (1);
}

int check_arg(char *arg, t_stack *a)
{
	int num;

	num = ft_atoi(arg);
	while (arg && *arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	while (a)
	{
		if (num == a->item)
			return (0);
		a = a->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (exit_error(&a, &b));
	while (--argc)
		if(!check_arg(argv[argc], a))
			return (exit_error(&a, &b));
		else
			ft_lstadd_front(&a, ft_lstnew(ft_atoi(argv[argc])));
	if (TYPE_OUTPUT == 2)
		print_comand("Init a and b:\n", a, b);
	pa(&a,&b);
	rra(&a, &b);
	return(0);
}