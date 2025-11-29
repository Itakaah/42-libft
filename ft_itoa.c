#include "libft.h"

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_res(char *res, int n, int len)
{
	int	i;

	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	if (n == 0)
		res[0] = '0';
	i = len - 1;
	while (n > 0)
	{
		res[i--] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	ft_res(res, n, len);
	return (res);
}