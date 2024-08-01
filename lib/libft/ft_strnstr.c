/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:59:06 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:59:06 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strnstr - Locate a substring in a string with length limit.
** const char *s1	: The string to be searched.
** const char *s2	: The substring to be located.
** size_t n			: The maximum number of characters to search.
**
** DESCRIPTION: This function locates the first occurrence of the null
** terminated string 's2' in the string 's1', where not more than 'n' characters
** are searched. Characters after a '\0' are not searched.
**
** Return: A pointer to the first character of the first occurrence of 's2',
** or NULL if 's2' is not found.
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (*(s1 + i) && i < n)
	{
		j = 0;
		while (*(s1 + i + j) && i + j < n && *(s1 + i + j) == *(s2 + j))
		{
			if (!*(s2 + j + 1))
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main()
{
	char *str1 = "aaaaHahaaaaaaa";
	char *str2 = "Haha";
	char *str3 = "Baba";
	char *ptr = NULL;

	ptr = ft_strnstr(str1, str2, 10);
	if  (ptr)
		printf("Haha in s1 found!\n");
	else
		printf("Haha not in s1 found!\n");
	ptr = ft_strnstr(str1, str3, 10);
	if  (ptr)
		printf("Baba in s1 found!\n");
	else
		printf("Baba not in s1 found!\n");
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_strnstr.c
