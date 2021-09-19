#include "push_swap.h"


int check_arg(char *arg, t_stack *a, int *num)
{
	*num = 0;
	while (arg[*num] == '-' || arg[*num] == '+' )
		(*num)++;
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