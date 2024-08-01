/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:59:11 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:59:11 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strrchr - Locate the last occurrence of a character in a string.
** const char *s	: The string to be searched.
** int c			: The character to be located.
**
** DESCRIPTION: This function searches for the last occurrence of the
** character 'c' in the string 's'. The terminating null byte is considered
** part of the string, so if 'c' is '\0', the function locates the
** terminating '\0'.
**
** RETURN: A pointer to the last occurrence of the character 'c' in the
** string 's', or NULL if the character is not found.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (!(char)c)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main()
{
	char *str = "aaaaaaaaaaaabaaaaa";
	char *ptr = NULL;

	ptr = ft_strrchr(str, 'b');
	if (ptr && *ptr)
		printf("%c found!\n", ft_toupper(*ptr));
	else
		printf("Search failed!\n");
	ptr = ft_strrchr(str, 'c');
	if (ptr && *ptr)
		printf("%c found!\n", ft_toupper(*ptr));
	else
		printf("Search failed!\n");
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_strrchr.c ft_strlen.c ft_toupper.c
