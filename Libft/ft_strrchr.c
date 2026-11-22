/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:01:28 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/13 10:03:17 by adabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	if (c == '\0')
		return ('\0');
	return (NULL);
}
#include <string.h>
#include <stdio.h>
int main()
{
	char *s = "hello world";
	printf("%s\n", ft_strrchr(s, 'a'));
	printf("%s", strrchr(s,'a'));
}