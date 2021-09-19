#include "push_swap.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)destination)[i] = c;
		i++;
	}
	return (destination);
}
