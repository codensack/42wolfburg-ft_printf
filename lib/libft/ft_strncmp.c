/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:59:00 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:59:00 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strncmp - Compare two strings up to a specified number of characters.
** const char *s1	: The first string to be compared.
** const char *s2	: The second string to be compared.
** size_t n			: The maximum number of characters to compare.
**
** DESCRIPTION: This function compares up to 'n' characters of the strings
** 's1' and 's2'. The comparison is done lexicographically. It stops comparing
** either after 'n' characters have been compared, or a null character is
** encountered.
**
** RETURN: An integer less than, equal to, or greater than zero if 's1' is
** found, respectively, to be less than, to match, or be greater than 's2'.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*s1 || *s2))
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

	printf("ft_strncmp(str1, str2, 4):\t%d\n", ft_strncmp(str1, str2, 4));
	printf("strncmp(str1, str2, 4):\t\t%d\n", strncmp(str1, str2, 4));
	printf("ft_strncmp(str1, str3, 4):\t%d\n", ft_strncmp(str1, str3, 4));
	printf("strncmp(str1, str3, 4):\t\t%d\n", strncmp(str1, str3, 4));
	printf("ft_strncmp(str1, str4, 4):\t%d\n", ft_strncmp(str1, str4, 4));
	printf("strncmp(str1, str4, 4):\t\t%d\n", strncmp(str1, str4, 4));
	return (0);
}
*/

// gcc -Werror -Wall -Wextra
