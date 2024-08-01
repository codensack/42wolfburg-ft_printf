/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:36 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:58:36 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strlcat - Concatenate strings with size limit.
** char *dst		: The destination buffer where the string is to be
**						concatenated.
** const char *src	: The source string to be appended.
** size_t size		: The size of the destination buffer.
**
** DESCRIPTION: This function appends the null-terminated string 'src' to
** the end of 'dst'. It will append at most 'dstsize - strlen(dst) - 1' bytes,
** null-terminating the result. If 'size' is 0 or less than the length of
** 'dst', it only returns the length of 'src' plus 'dstsize'.
**
** RETURN: The total length of the string it tried to create, which is the
** initial length of 'dst' plus the length of 'src'.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (src_len + size);
	ft_strlcpy(dst + dst_len, src, size - dst_len);
	return (dst_len + src_len);
}

/*
#include <stdio.h>

int main()
{
	const char	src[] = "Work smart and hard!";
	char		dst[30] = "U better ";
	size_t		len_of_both_str = (ft_strlen(src) + ft_strlen(dst));
	size_t		result = ft_strlcat(dst, src, 20);

	printf("The dest is: %s\n", dst);
	printf("Src_len + dst_len is: %zu\n", len_of_both_str);
	printf("Return from ft_strcat is: %zu\n", result);
}
*/

// gcc -Werror -Wall -Wextra ft_strlcat.c ft_strlen.c
