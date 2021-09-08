#include "push_swap.h"

int exit_error(t_stack **a)
{
	ft_lstclear(a);
	ft_putstr_fd("ERROR\n", 1);
	return (1);
}

int check_arg(char *arg, t_stack *a, int *num)
{
	*num = 0;
	while (arg[*num])
	{
		if (!ft_isdigit(arg[*num]))
			return (0);
		(*num)++;
	}
	*num = ft_atoi(arg);
	if ((*num == -1 && arg[2] != '\0') || (*num == 0 && arg[1] != '\0'))
		return (0);  
	while (a)
	{
		if (*num == a->item)
			return (0);
		a = a->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int		num;
	t_stack *a;
	t_stack *b;
	t_stack *comands;

	a = NULL;
	b = NULL;
	comands = NULL;
	if (argc < 2)
		return (exit_error(&a));
	while (--argc)
		if(!check_arg(argv[argc], a, &num))
			return (exit_error(&a));
		else
			ft_lstadd_front(&a, ft_lstnew(num));
	ft_sort(&a);
	ft_putnbr_fd(a->num, 1);
	return(0);
}