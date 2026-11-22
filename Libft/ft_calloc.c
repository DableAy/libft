/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 13:08:40 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/15 17:01:00 by adabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	p = malloc(size * nmemb);
	if (!p)
		return (NULL);
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
// #include <stdio.h>
// int	main(void)
// {
// 	size_t	count;
// 	size_t	i;
// 	int		*arr;

// 	count = 5;
// 	arr = (int *)ft_calloc(count, sizeof(int));
// 	if (!arr)
// 	{
// 		printf("Allocation failed\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (i < count)
// 	{
// 		printf("arr[%zu] = %d\n", i, arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }
