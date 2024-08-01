/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:55:40 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:55:40 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_calloc - Allocate and zero-initialize array.
** size_t nmemb	: The number of elements to be allocated.
** size_t size	: The size of each element.
**
** DESCRIPTION: This function allocates memory for an array of 'nmemb'
** elements of 'size' bytes each and initializes all its bits to zero.
** The memory is dynamically allocated and needs to be freed by the caller.
**
** RETURN: A Pointer to the allocated memory or NULL if the allocation fails.
**/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;

	if (nmemb * size > INT_MAX)
		return ((void *)0);
	r = malloc(nmemb * size);
	if (!r)
		return ((void *)0);
	ft_bzero(r, nmemb * size);
	return (r);
}

/*
#include <stdio.h>

int main()
{
    int num_elements = 5;
    int *arr;
	int i = 0;

    arr = (int *)ft_calloc(num_elements, sizeof(int));
    if (!arr)
        return (1);
    printf("Memory allocated by ft_calloc: ");
	while (i < num_elements)
        printf("%d", arr[i++]);
    printf("\n");
    free(arr);
    return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_calloc.c ft_bzero.c ft_memset.c
