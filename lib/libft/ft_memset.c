/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:57:38 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:57:38 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memset - Fill a block of memory with a specific value.
** void s	: The memory area to be filled.
** int c	: The value to be set.
** size_t n	: The number of bytes to be set to the value.
**
** DESCRIPTION: This function fills the first 'n' bytes of the memory area
** pointed to by 's' with the constant byte 'c'.
**
** RETURN: A pointer to the memory area 's'.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	void	*r;

	r = s;
	while (n--)
		*(char *)s++ = (char)c;
	return (r);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[10] = {'\0'};
	char str2[10] = {'\0'};
	char c = 'X';
	ft_memset(str1, c, 9);
	memset(str2, c, 9);
	printf("ft_memset result:\t%s\n", str1);
	printf("memset result:\t\t%s\n", str1);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_memset.c
