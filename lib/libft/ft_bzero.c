/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:55:08 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:55:08 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_bzero - Zero a block of memory.
** void *s	: The memory address to be zeroed from.
** size_t n	: The number of bytes to be zeroed.
**
** DESCRIPTION: This function sets the first 'n' bytes of the memory area
** pointed to by 's' to zero (bytes containing '\0').
**
** RETURN: None
**/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*
#include <stdio.h>

int main()
{
	char s[] = "Hello";
	int s_len = sizeof(s) - 1;
	int n = 2;
	int i = 0;
	ft_bzero(&s[2], (size_t)n);
	printf("The string is ");
	while (i < s_len)
	{
		if (!s[i])
			printf("_");
		printf("%c", s[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_bzero.c ft_memset.c
