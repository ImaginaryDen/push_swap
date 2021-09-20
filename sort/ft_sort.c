#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_choice(int *arr, int **link, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		swap(&arr[i], &arr[min]);
		swap((int *)&link[i], (int *)&link[min]);
		*link[i] = i + 1;
		i++;
	}
}

void	ft_sort(t_stack *stack)
{
	int		size;
	int		i;
	int		*arr;
	int		**link;

	size = ft_lstsize(stack);
	arr = malloc(sizeof(int) * size);
	link = malloc(sizeof(int *) * size);
	i = 0;
	while (stack)
	{
		arr[i] = stack->item;
		link[i] = &(stack->order);
		stack = stack->next;
		i++;
	}
	ft_sort_choice(arr, link, size);
	while (i)
	{
		*(link[i - 1]) = i;
		i--;
	}
	free(link);
	free(arr);
}
