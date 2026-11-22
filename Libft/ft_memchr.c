/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:24:08 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/15 13:25:06 by adabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
#include <string.h>
#include <stdio.h>

int main()
{
	char s[10] = "";
	printf("%p\n", ft_memchr(s, 'a', 7));
	printf("%p", memchr(s, 'a', 7));
}