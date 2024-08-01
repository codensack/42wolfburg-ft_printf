/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:08:48 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/13 12:37:02 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstmap - Create a new list with modified content.
** t_list *lst			: The original list to iterate.
** void *(*f)(void *)	: The function to apply to each content of the list.
** void (*del)(void *)	: The function to delete a single element's content.
**
** DESCRIPTION: Iterates the linked list 'lst' and applies the function 'f' to
** each content. Creates a new list resulting from the applications of 'f'.
** If the allocation fails, it cleans up the allocated memory.
**
** RETURNS: A new list resulting from the applications of 'f', or NULL if the
** allocation fails or any parameter is NULL.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*nd;
	void	*modified_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		modified_content = f(lst->content);
		nd = ft_lstnew(modified_content);
		if (!nd)
		{
			del(modified_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, nd);
		lst = lst->next;
	}
	return (new_lst);
}

/*
** We need the variable: "modified_content" to make sure we don't lose
** access to that memory in case "nd = ft_lstnew(modified_content)" fails.
** If we wouldn't use this variable to store the memoryaddress and write
** "nd = in ft_lstnew(f(lst->content)" instead, then the address of the
** allocated memory is stored nowhere and in error case it is lost and
** we are not able to release the memory correctly.
*/

/*
#include <stdio.h>

void	*add_42(void *ptr)
{
	*(int *)ptr += 42;
	return (ptr);
}

int main()
{
	t_list	*lst;
	t_list	*mod_lst;
	t_list	*lst_tmp;
	int		*value1 = (int *)malloc(sizeof(int));
	int		*value2 = (int *)malloc(sizeof(int));

	if (!value1 || !value2)
		return (1);
	*value1 = 1;
	*value2 = 2;
	if(!(lst = ft_lstnew(value1)))
		return (1);
	if (!(lst->next = ft_lstnew(value2)))
		return (1);
	lst_tmp = lst;
	printf("The original list:\n");
	while (lst_tmp)
	{
		printf("The nodes are %d\n", *(int *)lst_tmp -> content);
		lst_tmp = lst_tmp->next;
	}
	printf("The new list is:\n");
	mod_lst = ft_lstmap(lst, add_42, free);
	lst_tmp = mod_lst;
	while (lst_tmp != NULL)
	{
		printf("The new list value are %d\n", *(int *)lst_tmp->content);
		lst_tmp = lst_tmp->next;
	}
	ft_lstclear(&mod_lst, free);
}
*/

// gcc -Werror -Wall -Wextra ft_lstmap_bonus.c ft_lstclear_bonus.c
// ft_lstadd_back_bonus.c ft_lstnew_bonus.c ft_lstdelone_bonus.c
// ft_lstlast_bonus.c
