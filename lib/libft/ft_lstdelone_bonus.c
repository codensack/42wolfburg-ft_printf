/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:47:00 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/13 10:28:46 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstdelone - Delete a node and free its content using a given function.
** t_list *lst			: Pointer to the node to be deleted.
** void (*del)(void *)	: Pointer to the function used to delete the content of
**							the node.
**
** DESCRIPTION: Deletes the node 'lst' and frees its content using the function
** 'del'. The memory of 'lst' itself is also freed. Does nothing if 'lst' 
** is NULL.
**
** RETURN: None
**/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
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

	lst_tmp = lst;
	while (lst_tmp)
	{
		printf("The nodecontent is %d\n", *(int *)lst_tmp->content);
		lst_tmp = lst_tmp->next;
	}
	printf("Deletion of lst->next with content: %d\n", \
		*(int *)lst->next->content);
	ft_lstdelone(lst->next, free);
	lst->next = NULL; // override the address of the freed memoryspace
	printf("Deletion of lst with content: %d\n", *(int *)lst->content);
	ft_lstclear(&lst, free);
}
*/

// gcc -Werror -Wall -Wextra ft_lstdelone_bonus.c ft_lstnew_bonus.c
// ft_lstclear_bonus.c
