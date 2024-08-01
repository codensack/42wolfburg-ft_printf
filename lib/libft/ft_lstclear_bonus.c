/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:52:50 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/13 12:30:21 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_listclear - Delete all nodes of a lst and their content using a given
** function.
** t_list **lst			: Pointer to the pointer to the first node of the lst.
** void (*del)(void *)	: The function used to delete the content of each node.
**
** DESCRIPTIOPN: Deletes all nodes of the lst starting from 'lst' and frees
** their content using the function 'del'. Updates 'lst' to NULL. Does nothing
** if 'lst' or 'del' is NULL.
**
** RETURN: None
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/*
#include <stdio.h>

int main()
{
    t_list	*lst;
	t_list	*lst_tmp;
    int	*value1 = (int *)malloc(sizeof(int));
    int	*value2 = (int *)malloc(sizeof(int));
    int	*value3 = (int *)malloc(sizeof(int));

    if (!value1 || !value2 || !value3)
        return 1;
    *value1 = 24;
    *value2 = 42;
    *value3 = 1;
    if (!(lst = ft_lstnew(value1)))
        return 1;
    if (!(lst->next = ft_lstnew(value2)))
        return 1;
    if (!(lst->next->next = ft_lstnew(value3)))
        return 1;
    lst_tmp = lst;
    while (lst_tmp)
    {
        printf("Node value: %d\n", *(int *)(lst_tmp->content));
        lst_tmp = lst_tmp->next;
    }
    ft_lstclear(&lst, free);
    if (lst == NULL)
        printf("lst has been cleared successfully.\n");
    else
        printf("lst has not been cleared successfully.\n");
    return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_lstclear_bonus.c ft_lstdelone_bonus.c
// ft_lstnew_bonus.c
