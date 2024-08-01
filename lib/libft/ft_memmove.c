/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:57:32 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:57:32 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memmove - Copy memory area with overlapping regions.
** void *dest		: The destination buffer where the content is to be copied.
** const void *src	: The source buffer from where the content is to be copied.
** size_t n			: The number of bytes to be copied.
**
** DESCRIPTION: This function copies 'n' bytes from memory area 'src' to
** memory area 'dest'. The memory areas may overlap, and the copy is done
** in a safe way.
**
** RETURN: A pointer to the destination buffer 'dest'.
**/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*r;

	if (!dest && !src)
		n = 0;
	r = dest;
	if (dest < src)
		while (n--)
			*(char *)dest++ = *(char *)src++;
	else
		while (n--)
			*(char *)(dest + n) = *(char *)(src + n);
	return (r);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char *str1 = ft_strdup("aaaaaaaaaa");
	char *str2 = ft_strdup("aaaaaaaaaa");
	char *str3 = ft_strdup("bbbbbbbbbb");

	ft_memmove(str1, str3, 4);
	memmove(str2, str3, 4);
	printf("ft_memmove result:\t%s\n", str1);
	printf("memmove result:\t\t%s\n", str2);
	free(str1);
	free(str2);
	free(str3);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_memmove.c ft_strdup.c ft_strlen.c
