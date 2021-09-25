#include "push_swap.h"

int	find_min_magic(t_stack *stack, t_stack **commands)
{
	t_stack	*copy_stack;
	int		min;
	int		magic_min;
	int		size;
	int		max_check;

	max_check = 15;
	if (ft_lstsize(stack) < 90)
		max_check = 2;
	while (max_check)
	{
		copy_stack = ft_lstcopy(stack);
		ft_sort_stack(&copy_stack, commands, max_check);
		ft_command_cheker(*commands);
		size = ft_lstsize(*commands);
		if (!min || min > size)
		{
			min = size;
			magic_min = max_check;
		}
		ft_lstclear(&copy_stack);
		ft_lstclear(commands);
		max_check--;
	}
	return (magic_min);
}

void	find_solve(t_stack **commands, t_stack *stack)
{
	t_stack	*copy_stack;

	copy_stack = ft_lstcopy(stack);
	if (ft_lstsize(copy_stack) <= 6)
		mini_sort(&copy_stack, commands);
	else
		ft_sort_stack(&copy_stack, commands, find_min_magic(stack, commands));
	ft_command_cheker(*commands);
	ft_lstclear(&copy_stack);
}

int	main(int argc, char **argv)
{
	int		ret;
	char	**strs;
	t_stack	*stack;
	t_stack	*commands;

	stack = NULL;
	commands = NULL;
	if (argc < 2)
		return (0);
	if (pars_arg(argv + 1, argc - 1, &stack))
	{
		strs = ft_split(argv[1], ' ');
		ret = pars_arg(strs, get_size_str(strs), &stack);
		ft_free_dabl_arr(strs);
		if (ret)
			return (exit_error(&stack, NULL, 1));
	}
	if (ft_is_sort(stack, NULL))
		return (exit_error(&stack, NULL, 0));
	find_solve(&commands, stack);
	print_commands(commands);
	ft_lstclear(&stack);
	ft_lstclear(&commands);
	return (0);
}
