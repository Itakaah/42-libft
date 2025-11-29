#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	total;

	total = count * size;
	if (count != 0 && total / count != size)
		return (NULL);
	res = malloc(total);
	if (!res)
		return (NULL);
	ft_bzero(res, total);
	return (res);
}