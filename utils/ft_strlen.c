#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	const char	*s_c = s;

	while (*s_c)
		s_c++;
	return (s_c - s);
}
