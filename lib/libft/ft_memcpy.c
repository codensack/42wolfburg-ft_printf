/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:57:24 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:57:24 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcpy - Copy memory area.
** void *dest		: The destination buffer where the content is to be copied.
** const void *src	: The source buffer from where the content is to be copied.
** size_t n			: The number of bytes to be copied.
**
** DESCRIPTION: This function copies 'n' bytes from memory area 'src' to
** memory area 'dest'. The memory areas must not overlap. Use ft_memmove if
** the memory areas do overlap.
**
** RETURN: A pointer to the destination buffer 'dest'.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*r;

	if (!dest && !src)
		n = 0;
	r = dest;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (r);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[6] = "Hallo";
	char str2[6];
	char str3[6];

	ft_memcpy(str2, str1, 6);
	memcpy(str3, str1, 6);
	printf("ft_memcpy result: %s\n", str2);
	printf("memcpy result: %s\n", str3);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_memcpy.c
