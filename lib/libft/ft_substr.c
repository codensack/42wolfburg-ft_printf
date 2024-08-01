/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:59:21 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:59:21 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_substr - Extract a substring from a string.
** char const *s		: The string from which to extract the substring.
** unsigned in start	: The starting index of the substring in 's'.
** size_l len			: The maximum length of the substring.
**
** DESCRIPTION: Allocates and returns a substring from the string 's'
** beginning at index 'start' for up to 'len' characters.
** The substring is terminated with '\0'.
** If 'start' is beyond the end of 's', the function returns NULL.
**
** RETURN: The substring extracted from 's', or NULL
** if memory allocation fails or 'start' is out of range.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	r = malloc(len + 1);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s + start, len + 1);
	return (r);
}

/*
#include <stdio.h>

int main()
{
	char *str = "aaaaaHalloaaaaa";
	char *ptr;
	ptr = ft_substr(str, 5, 5);
	printf("%s\n", ptr);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_substr.c ft_strdup.c ft_strlen.c ft_strlcpy.c
