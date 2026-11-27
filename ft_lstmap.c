/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adabdall <adabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 14:33:48 by adabdall          #+#    #+#             */
/*   Updated: 2026/11/27 18:30:00 by adabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*clear_list(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	tail = NULL;
	while (lst)
	{
		node = malloc(sizeof(t_list));
		if (!node)
			return (clear_list(&head, del));
		node->content = f(lst->content);
		node->next = NULL;
		if (!head)
			head = node;
		else
			tail->next = node;
		tail = node;
		lst = lst->next;
	}
	return (head);
}

/*
#include <stdio.h>

static void	*dup_upper(void *content)
{
	char	*s;
	int		i;

	s = ft_strdup((char *)content);
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

int	main(void)
{
	t_list	*lst;
	t_list	*mapped;
	t_list	*tmp;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("hello"));
	ft_lstadd_back(&lst, ft_lstnew("world"));
	mapped = ft_lstmap(lst, dup_upper, free);
	tmp = mapped;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&mapped, free);
	ft_lstclear(&lst, NULL);
	return (0);
}
*/
