/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 08:39:24 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/19 11:05:35 by adabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*p;
	size_t		i;
	size_t		j;
	size_t		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	return (p);
}
#include <stdio.h>

int main()
{
	char *s1 = "";
	char *s2 = "";
	printf("%s", ft_strjoin(s1,s2));
}