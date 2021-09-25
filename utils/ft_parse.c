#include "push_swap.h"

int	pars_arg(char **argv, int argc, t_stack **stack)
{
	int	num;
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!check_arg(argv[i], *stack, &num))
			return (1);
		else
			ft_lstadd_back(stack, ft_lstnew(num));
		i++;
	}
	return (0);
}

void	ft_free_dabl_arr(char **strs)
{
	int	i;

	i = 0;
	while (strs + i && strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
