/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:12:46 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/13 11:12:08 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_lstadd_front - Add a new node with the specified content at the beginning
** of a list.
** t_list **lst	: A pointer to the pointer to the first node of the list.
** t_list *new	: The new node to add to the beginning of the list.
**
** DESCRIPTION: Adds the new node 'new' with the specified content to the
** beginning of the list pointed to by 'lst'. Updates 'lst' to point to the new
** first node.
**
** RETURN: None
**/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
#include <stdio.h>

int main()
{
	t_list	*lst;
	t_list	*last_node;
	int		*value1;
	char	*value2;
	int		*value3;

	value1 = (int *)malloc(sizeof(int));
	if (value1 == NULL)
		return (1);
	*value1 = 24;
	if (!(lst = ft_lstnew(value1)))
		return (1);

	if (!(value2 = (char *)malloc(6 * sizeof(char))))
		return (1);
	ft_strlcpy(value2, "Hallo", 6);
	if (!(lst->next = ft_lstnew(value2)))
		return (1);

	if (!(value3 = (int *)malloc(sizeof(int))))
		return (1);
	*value3 = 42;
	if (!(last_node = ft_lstnew(value3)))
		return (1);
	ft_lstadd_front(&lst, last_node);

	printf("The first listnode content is: %d\n", *(int *)lst->content);
	lst = lst->next;
	printf("The second listnode content is: %d\n", *(int *)lst->content);
	lst = lst->next;
	printf("The last listnode content is: %s\n", (char *)lst->content);
	ft_lstclear(&lst, free);
}
*/

// gcc -Werror -Wall -Wextra ft_lstadd_front_bonus.c ft_lstnew_bonus.c
// ft_lstclear_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c ft_strlcpy.c
// ft_strlen.c
