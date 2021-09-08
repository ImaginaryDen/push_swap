#include "push_swap.h"

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void swap_link(int **a, int **b)
{
	int *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_sort(t_stack **stack)
{
	int		size;
	int		i;
	int		j;
	int		min;
	int 	*arr;
	int		**link;
	t_stack *temp;

	size = ft_lstsize(*stack);
	arr = malloc(sizeof(int) * size);
	link = malloc(sizeof(int *) * size);
	temp = *stack;
	i = 0;
	while (temp)
	{
		arr[i] = temp->item;
		link[i] = &(temp->num);
		temp = temp->next;
		i++;
	}
	i = 0;
	while(i + 1 < size)
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
		swap_link(&link[i], &link[min]);
		i++;
	}
	i = 0;
	while(i < size)
	{
		*(link[i]) = i;
		i++;
	}
}