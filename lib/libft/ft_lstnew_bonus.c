/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:50:01 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/13 11:09:10 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstnew - Create a new list node.
** void *content	: The content to be added to the new node.
**
** DESCRIPTION: Allocates a new list node with the given content.
** If 'content' is NULL, initializes the 'content' pointer in the new node to
** NULL.
**
** RETURN: The newly allocated list node, or NULL if allocation fails.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return ((void *)0);
	lst->content = content;
	lst->next = (void *)0;
	return (lst);
}

/*
#include <stdio.h>

int main()
{
	int value1 = 40;
	int value2 = 41;
	int value3 = 42;
	t_list	*node1 = ft_lstnew(&value1);
	t_list	*node2 = ft_lstnew(&value2);
	t_list	*node3 = ft_lstnew(&value3);
	t_list	*current;
	t_list	*tmp;

	node1 -> next = node2;
	node2 -> next = node3;
	current = node1;
	while (current)
	{
		printf("The content of this listnode is %d\n", *(int *)current->content);
		current = current->next;
	}
	current = node1;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}
*/

// gcc -Werror -Wall -Wextra ft_lstnew_bonus.c
