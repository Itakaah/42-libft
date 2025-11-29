#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_temp;
	unsigned char		c_temp;

	s_temp = (const unsigned char *)s;
	c_temp = (unsigned char)c;
	while (n--)
	{
		if (*s_temp == c_temp)
			return ((void *)s_temp);
		s_temp++;
	}
	return (NULL);
}