/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:57:18 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:57:18 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcmp - Compare two blocks of memory.
** const void *s1	: The first memory block to be compared.
** const void *s2	: The second memory block to be compared.
** size_t n		: The number of bytes to be compared.
**
** DESCRIPTION: This function compares the first 'n' bytes of the memory
** areas 's1' and 's2'. The comparison is done byte by byte.
**
** RETURN: An integer less than, equal to, or greater than zero if the first
** 'n' bytes of 's1' is found, respectively, to be less than, to match, or
** be greater than the first 'n' bytes of 's2'.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
			return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char *str1 = "abcdefg";
	char *str2 = "abddefg";
	char *str3 = "abbdefg";
	char *str4 = "abcdefg";

	printf("ft_memcmp(str1, str2, 4):\t%d\n", ft_memcmp(str1, str2, 4));
	printf("memcmp(str1, str2, 4):\t\t%d\n", memcmp(str1, str2, 4));
	printf("ft_memcmp(str1, str3, 4):\t%d\n", ft_memcmp(str1, str3, 4));
	printf("memcmp(str1, str3, 4):\t\t%d\n", memcmp(str1, str3, 4));
	printf("ft_memcmp(str1, str4, 4):\t%d\n", ft_memcmp(str1, str4, 4));
	printf("memcmp(str1, str4, 4):\t\t%d\n", memcmp(str1, str4, 4));
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_memcmp.c
