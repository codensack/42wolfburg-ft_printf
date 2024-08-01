/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:59:16 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:59:16 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strtrim - Trim leading and trailing whitespaces from a string.
** char const *s1	: The string to be trimmed.
** char const *set	: The set of characters to trim.
**
** DESCRIPTION: Allocates and returns a copy of the string 's1' with the
** leading and trailing characters from the 'set' removed.
**
** RETURN: The trimmed string, or NULL if memory allocation fails.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_end;
	char	*r;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (!*s1)
		s1_end = (char *)s1;
	else
		s1_end = (char *)s1 + ft_strlen(s1) - 1;
	while ((s1_end != s1) && ft_strchr(set, *s1_end))
		s1_end--;
	r = ft_substr(s1, 0, s1_end + 1 - s1);
	return (r);
}

/*
#include <stdio.h>

int main()
{
	char *str = "abccbaddddccccdddddabccba";
	char *set = "abc";
	char *ptr;

	ptr = ft_strtrim(str, set);
	printf("%s\n", ptr);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_strtrim.c ft_strlen.c ft_strchr.c ft_substr.c
// ft_strlcpy.c ft_strdup.c
