/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:06:03 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/13 10:28:20 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstiter - Iterate over each node of a list and apply a function to its
**	content.
** t_list *lst			: The beginning of the list.
** void (f*)(void *)	: The function to apply to the content of each node.
**
** DESCRIPTION: Iterates over each node of the list starting from 'lst' and
** applies the function 'f' to the content of each node.
**
** RETURN: None
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>

void	print_content(void *ptr)
{
	printf("Content is %d\n", *(int *)ptr);
}

int main()
{
	t_list	*lst;
	int		*value1 = (int *)malloc(sizeof(int));
	int		*value2 = (int *)malloc(sizeof(int));

	if (!value1 || !value2)
		return (1);
	*value1 = 56;
	lst = ft_lstnew(value1);
	*value2 = 78;
	lst->next = ft_lstnew(value2);
	ft_lstiter(lst, print_content);
	ft_lstclear(&lst, free);
}
*/

// gcc -Werror -Wall -Wextra ft_lstiter_bonus.c ft_lstnew_bonus.c
// ft_lstclear_bonus.c ft_lstdelone_bonus.c
