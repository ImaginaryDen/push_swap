#include "push_swap.h"

int	exit_error(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	ft_putstr_fd("Error\n", 1);
	return (1);
}

int	parse_command(char *str)
{
	int			i;
	const char	name[11][4] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(name[i], str, 4))
			return (i);
		i++;
	}
	return (-1);
}

int	parse_commands_fd(t_stack	**command, int fd)
{
	int			i;
	int			ret;
	char		buf[5];

	i = 0;
	ft_memset(buf, 0, 4);
	while (1)
	{
		ret = read(fd, buf + i, 1);
		if (i == 5)
			return (0);
		if (*buf && (buf[i] == '\n' || ret == 0))
		{
			buf[i] = 0;
			if (parse_command(buf) == -1)
				return (0);
			ft_lstadd_back(command, ft_lstnew(parse_command(buf)));
			i = -1;
			ft_memset(buf, 0, 4);
		}
		if (ret == 0)
			return (*buf == 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*commands;
	int		num;

	if (argc < 2)
		return (1);
	stack = NULL;
	commands = NULL;
	while (--argc)
	{
		if (!check_arg(argv[argc], stack, &num))
			return (exit_error(&stack, &commands));
		else
			ft_lstadd_front(&stack, ft_lstnew(num));
	}
	if (!parse_commands_fd(&commands, 0))
		return (exit_error(&stack, &commands));
	ft_check(&stack, commands);
	ft_lstclear(&stack);
	ft_lstclear(&commands);
	return (0);
}
