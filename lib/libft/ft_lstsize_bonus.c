/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:22:28 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/13 10:30:15 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstsize - Count the number of elements in a list.
** t_list *lst	: The beginning of the list.
**
** DESCRIPTION: Counts and returns the number of nodes in the list starting
** from 'lst'.
**
** RETURN: The number of elements in the list.
*/

int	ft_lstsize(t_list *lst)
{
	int	c_lst;

	c_lst = 0;
	while (lst)
	{
		lst = lst->next;
		c_lst++;
	}
	return (c_lst);
}

/*
#include <stdio.h>

int main()
{
	t_list	*lst;
	int	*value1;
	int	*value2;
	int	*value3;
	int	count;

	if (!(value1 = (int *)malloc(sizeof(int))))
		return (1);
	*value1 = 2;
	if (!(lst = ft_lstnew(value1)))
		return (1);
	if (!(value2 = (int *)malloc(sizeof(int))))
		return (1);
	*value2 = 24;
	if (!(lst->next = ft_lstnew(value2)))
		return (1);
	if (!(value3 = (int *)malloc(sizeof(int))))
		return (1);
	*value2 = 42;
	if (!(lst->next->next = ft_lstnew(value3)))
		return (1);
	count = ft_lstsize(lst);
	printf("The number of nodes is %d\n", count);
	free(value3);
	free(lst->next->next);
	free(value2);
	free(lst->next);
	free(value1);
	free(lst);
}
*/

// gcc -Werror -Wall -Wextra ft_lstsize_bonus.c ft_lstnew_bonus.c
