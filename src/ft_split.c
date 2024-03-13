/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:44:10 by sarajime          #+#    #+#             */
/*   Updated: 2024/02/14 12:33:15 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	word;
	int	inside_word;

	i = 0;
	word = 0;
	inside_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !inside_word)
		{
			inside_word = 1;
			word++;
		}
		else if (s[i] == c && inside_word)
			inside_word = 0;
		i++;
	}
	return (word);
}

static void	ft_free_everything(char **str)
{
	size_t	a;

	a = 0;
	while (str[a])
	{
		free(str[a]);
		a++;
	}
	free(str);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		len = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**ft_split_content(char **str, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		k = j;
		while (s[j] && s[j] != c)
			j++;
		if (k < j)
		{
			str[i] = ft_substr(s, k, j - k);
			if (!str[i])
			{
				ft_free_everything(str);
				return (NULL);
			}
			i++;
		}
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = (char **)malloc (sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!str || !s)
		return (NULL);
	str[ft_count_words(s, c)] = NULL;
	return (ft_split_content(str, s, c));
}
