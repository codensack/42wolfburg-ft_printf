/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:57:08 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:57:08 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memchr - Locate a byte in memory.
** const void *s	: The memory area to be searched.
** int c			: The byte to be located.
** size_t n			: The number of bytes to be searched.
**
** DESCRIPTION: This function searches the first 'n' bytes of the memory area
** pointed to by 's' for the first occurrence of the byte 'c'. The search stops
** when the byte is found or 'n' bytes have been searched.
**
** RETURN: A Pointer to the matching byte or NULL if the byte is not found.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	const char str[] = "jkashd jas daksjd alksjd aksjd";
	char c = 'd';
	
	char *result = ft_memchr(str, c, 8);
	char *result1 = memchr(str, c, 8);
	printf("ft_memchr located the byte searched for at:\t%p\n", result);
	printf("memchr located the byte searched for at: \t%p\n", result1);
}
*/

// gcc -Werror -Wall -Wextra ft_memchr.c
