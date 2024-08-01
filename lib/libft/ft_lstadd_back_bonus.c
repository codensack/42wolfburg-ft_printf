/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:35:28 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/13 12:40:42 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstadd_back - Add a lst node with the specified content at the end of a
** list.
** t_list **lst		: A pointer to the pointer to the first node of the list.
** t_list *new		: The lst node to add to the end of the list.
**
** DESCRIPTION: Adds the lst node 'new' with the specified content to the end
** of the list pointed to by 'lst'. Updates 'lst' if it's initially NULL.
**
** RETURN: None
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l_lst;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	l_lst = ft_lstlast(*lst);
	l_lst->next = new;
}

/*
#include <stdio.h>

int main()
{
	t_list	*lst;
	t_list	*lst_tmp;
	t_list	*last_node;
	int	*value1;
	char	*value2;
	int	*value3;

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
	ft_lstadd_back(&lst, last_node);
	lst_tmp = lst;
	printf("The first listnode content is: %d\n", *(int *)lst_tmp->content);
	lst_tmp = lst_tmp->next;
	printf("The second listnode content is: %s\n", (char *)lst_tmp->content);
	lst_tmp = lst_tmp->next;
	printf("The last listnode content is: %d\n", *(int *)lst_tmp->content);
	ft_lstclear(&lst, free);
}
*/

// gcc -Werror -Wall -Wextra ft_lstadd_back_bonus.c ft_lstnew_bonus.c
// ft_lstclear_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c ft_strlcpy.c
// ft_strlen.c
