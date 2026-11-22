/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 09:18:08 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/22 13:44:34 by adabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	calc(int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*s;

	i = calc(n);
	nb = n;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	s[i--] = '\0';
	while (nb > 0)
	{
		s[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;

// 	str = ft_itoa(123456);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
