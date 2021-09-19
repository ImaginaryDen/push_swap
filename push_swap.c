#include "push_swap.h"

int		exit_error(t_stack **a)
{
	ft_lstclear(a);
	ft_putstr_fd("Error\n", 1);
	return (1);
}

void print_commands(t_stack *commands)
{
	const char	name[12][4] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	while (commands)
	{
		ft_putstr_fd((char *)name[commands->item], 1);
		ft_putstr_fd("\n", 1);
		commands = commands->next;
	}
}

void find_solve(t_stack **commands, t_stack *stack)
{
	t_stack *copy_stack;
	int	min;
	int	magic_min;
	int	i;
	int	size;
	int	max_check;

	i = 1;
	min = 0;
	max_check = 15;
	if (ft_lstsize(stack) < 100)
		max_check = 2;
	while (i < max_check)
	{
		copy_stack = ft_lstcopy(stack);
		ft_sort_stack(&copy_stack, commands, i);
		ft_command_cheker(*commands);
		size = ft_lstsize(*commands);
		if (!min || min > size)
		{
			min = size;
			magic_min = i;
		}
		ft_lstclear(&copy_stack);
		ft_lstclear(commands);
		i++;
	}
	copy_stack = ft_lstcopy(stack);
	ft_sort_stack(&copy_stack, commands, magic_min);
	ft_command_cheker(*commands);
	ft_lstclear(&copy_stack);
}

int main(int argc, char **argv)
{
	int		num;
	t_stack *stack;
	t_stack *commands;

	stack = NULL;
	commands = NULL;
	if (argc < 2)
		return (exit_error(&stack));
	while (--argc)
		if(!check_arg(argv[argc], stack, &num))
			return (exit_error(&stack));
		else
			ft_lstadd_front(&stack, ft_lstnew(num));
	if (ft_is_sort(stack, NULL))
		return (exit_error(&stack));
	find_solve(&commands, stack);
	print_commands(commands);
	//ft_check(&stack, commands);
	ft_lstclear(&stack);
	ft_lstclear(&commands);
	return(0);
}