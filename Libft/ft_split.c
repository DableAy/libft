/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 09:10:31 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/22 14:52:47 by adabdall         ###   ########.fr       */
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
		while (j < size && src[j] != '\0')
		{
			dest[j] = src[j];
			j++;
		}
	}
	dest[j] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char		**p;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	while (s[j])
	{
		if (s[j] == c)
		{
			ft_strlcpy(p[k], s, j);
			k++;
		}
		j++;
	}
	return (p);
}
// #include <stdio.h>

// int main()
// {
// 	char *s = "hello world";
// 	char **str = ft_split(s,'o');
// 	int i = 0;
// 	while (*str[i])
// 	{
// 		int j = 0;
// 		while (str[i][j])
// 		{
// 			printf("%s", str[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }