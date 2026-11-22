/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:32:28 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/15 13:23:09 by adabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr1;
	const char	*ptr2;

	i = 0;
	ptr1 = (char *)dest;
	ptr2 = (const char *)src;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return ((void *)(ptr1 + i));
}

#include <string.h>
#include <stdio.h>

int main()
{
	char s1[50] = "hello";
	char *s2 = "World";
	// memcpy(s1,s2,2);
	ft_memcpy(s1,s2,2);
	printf("%s", s1);
}