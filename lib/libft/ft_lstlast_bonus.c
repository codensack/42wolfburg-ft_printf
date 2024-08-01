/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:30:22 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/13 10:30:05 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstlast - Get the address of the last node in a list.
** t_list *lst	: The beginning of the list.
**
** DESCRIPTION: Traverses the list starting from 'lst' and returns a pointer
** to the last node.
**
** RETURNS: The last node of the list, or NULL if the list is empty.
*/

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

/*
#include <stdio.h>

int main()
{
	t_list	*lst;
	t_list	*lst_tmp;
	int		*value1;
	int		*value2;

	if (!(value1 = (int *)malloc(sizeof(int))))
		return (1);
	*value1 = 24;
	if (!(lst = ft_lstnew(value1)))
		return (1);
	if (!(value2 = (int *)malloc(sizeof(int))))
		return (1);
	*value2 = 42;
	if (!(lst->next = ft_lstnew(value2)))
		return (1);
	lst_tmp = ft_lstlast(lst);
	if ((lst_tmp = ft_lstlast(lst)))
		printf("The last node has as content: %d\n", *(int *)lst_tmp->content);
	ft_lstclear(&lst, free);
}
*/

// gcc -Werror -Wall -Wextra ft_lstlast_bonus.c ft_lstnew_bonus.c
// ft_lstclear_bonus.c ft_lstdelone_bonus.c
