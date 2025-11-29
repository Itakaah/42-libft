#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}