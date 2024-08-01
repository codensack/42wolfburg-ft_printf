/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:14 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:58:14 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strchr - Locate the first occurrence of a character in a string.
** const char *s	: The string to be searched.
** int c			: The character to be located.
**
** DESCRIPTION: This function searches for the first occurrence of the
** character 'c' in the string 's'. The terminating null byte is considered
** part of the string, so if 'c' is '\0', the function locates the
** terminating '\0'.
**
** RETURN: A pointer to the first occurrence of the character 'c' in the
** string 's', or NULL if the character is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>

int main()
{
    char *str = "Hello, world!";
    char *ptr = ft_strchr(str, 'w');
    if (ptr)
        printf("Character 'w' found at position: %ld\n", ptr - str);
    else
        printf("Character 'w' not found\n");
    return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_strchr.c
