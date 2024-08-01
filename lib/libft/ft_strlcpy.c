/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:42 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:58:42 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strlcpy - Copy a string to a buffer with size limit.
** char *dst		: The destination buffer where the string is to be copied.
** const char *src	: The source string to be copied.
** size_t size		: The size of the destination buffer.
**
** DESCRIPTION: This function copies up to 'size - 1' characters from
** the null-terminated string 'src' to 'dst', null-terminating the result.
** If 'size' is 0, the function does nothing.
**
** RETURN: The total length of the string it tried to create, which is
** the length of 'src'.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int			src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (*src && --size)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_len);
}

/*
#include <stdio.h>

int main()
{
	char str1[10];
	const char *str2 = "What's goin on?";

	ft_strlcpy(str1, str2, 5);
	printf("%s?\n", str1);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_strlcpy.c ft_strlen.c
