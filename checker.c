#include "push_swap.h"


int		exit_error(t_stack **a)
{
	ft_lstclear(a);
	ft_putstr_fd("Error\n", 1);
	return (1);
}

int parse_command(char *str)
{
	int			i;
	const char	name[11][4] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	
	i =	0;
	while (i < 11)
	{
		if (!ft_strncmp(name[i], str, 4))
			return (i);
		i++;
	}
	return (-1);
}

int parse_commands_fd(t_stack	**command, int fd)
{
	int			i;
	int			com;
	int			ret;
	char		buf[4];

	i = 0;
	while (i < 4)
		buf[i++] = 0;
	i = 0;
	while(1)
	{
		ret = read(fd, buf + i, 1);
		if (*buf && (buf[i] == '\n' || ret == 0 || i == 3))
		{
			buf[i] = 0;
			com = parse_command(buf);
			if (com == -1)
				return (0);
			ft_lstadd_back(command, ft_lstnew(com));
			i = 0;
			while (i < 4)
				buf[i++] = 0;
			i = -1;
		}
		if (ret == 0)
			return (1);
		i += 1;
	}
}

int main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack *commands;
	int		num;

	if (argc < 2)
		return (1);
	stack = NULL;
	commands = NULL;
	while (--argc)
		if(!check_arg(argv[argc], stack, &num))
			return (exit_error(&stack));
		else
			ft_lstadd_front(&stack, ft_lstnew(num));
	if (ft_is_sort(stack, NULL) || !parse_commands_fd(&commands, 1) || commands == NULL)
	{
		ft_lstclear(&stack);
		ft_lstclear(&commands);
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	ft_check(&stack, commands);
	ft_lstclear(&stack);
	ft_lstclear(&commands);
	return (0);
}