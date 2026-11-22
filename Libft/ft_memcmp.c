/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:39:24 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/15 13:34:24 by adabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*ptr1;
	const char	*ptr2;

	i = 0;
	ptr1 = (const char *)s1;
	ptr2 = (const char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
#include <string.h>
#include <stdio.h>

int main()
{
	char *s1 = "hello world";
	char *s2 = "hello hello";
	printf("%d\n", ft_memcmp(s1,s2,11));
	printf("%d", memcmp(s1,s2,11));
}
