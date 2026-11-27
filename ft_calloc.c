/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 13:08:40 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/27 18:30:00 by adabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

/*
#include <stdio.h>

int	main(void)
{
	int		*arr;
	size_t	i;

	arr = ft_calloc(5, sizeof(int));
	if (!arr)
		return (1);
	i = 0;
	while (i < 5)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
*/
