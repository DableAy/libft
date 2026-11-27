/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 09:10:31 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/27 18:30:00 by adabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] != '\0')
		i++;
	j = 0;
	if (size > 0)
	{
		while (j < size - 1 && src[j] != '\0')
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (i);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	j;

	count = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c && (j == 0 || s[j - 1] == c))
			count++;
		j++;
	}
	return (count);
}

static char	**free_all(char **p, size_t k)
{
	while (k > 0)
	{
		k--;
		free(p[k]);
	}
	free(p);
	return (NULL);
}

static char	**fill_words(char **p, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			i = j;
			while (s[j] && s[j] != c)
				j++;
			p[k] = malloc(sizeof(char) * (j - i + 1));
			if (!p[k])
				return (free_all(p, k));
			ft_strlcpy(p[k], s + i, j - i + 1);
			k++;
		}
	}
	p[k] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!p)
		return (NULL);
	return (fill_words(p, s, c));
}

// #include <stdio.h>

// int main()
// {
// 	char *s = "hello world";
// 	char **str = ft_split(s,'o');
// 	int i = 0;
// 	while (str[i])
// 	{
// 		printf("%s\n", str[i]);
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }
