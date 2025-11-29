#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	*ft_copy_word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = ft_word_len(s, c);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_free_all(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			res[j] = ft_copy_word(&s[i], c);
			if (!res[j])
			{
				ft_free_all(res, j);
				return (NULL);
			}
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	res[j] = NULL;
	return (res);
}