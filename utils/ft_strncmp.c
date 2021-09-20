#include "stdlib.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_u = (unsigned char*)s1;
	const unsigned char	*s2_u = (unsigned char*)s2;

	if (!n)
		return (0);
	i = 0;
	while (!(s1_u[i] - s2_u[i]) && s1_u[i] && s2_u[i] && i < n)
		i++;
	if (i == n)
		i--;
	return (s1_u[i] - s2_u[i]);
}
