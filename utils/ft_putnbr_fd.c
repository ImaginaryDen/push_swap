#include "push_swap.h"

static int	ft_pow(int num, int ft_pow_n)
{
	int	result;

	result = 1;
	while (ft_pow_n)
	{
		result *= num;
		ft_pow_n--;
	}
	return (result);
}

static int	ft_abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	size;
	int	copy_n;

	size = 0;
	copy_n = n;
	while (copy_n)
	{
		size++;
		copy_n /= 10;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (!n)
		ft_putchar_fd('0', fd);
	while (size)
	{
		ft_putchar_fd(ft_abs(n / ft_pow(10, size - 1)) + '0', fd);
		n %= ft_pow(10, size - 1);
		size--;
	}
}
