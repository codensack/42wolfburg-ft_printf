/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:31 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:58:31 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strjoin - Concatenate two strings into a new allocated string.
** char const *s1	: The first string.
** char const *s2	: The second string.
**
** DESCRIPTION: Allocates a new string that is the concatenation of
** 's1' and 's2'. The memory for the new string is dynamically allocated.
** Returns NULL if memory allocation fails.
**
** RETURN: The newly allocated string resulting from the
** concatenation of 's1' and 's2', or NULL if memory allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r1;

	if (!s1 || !s2)
		return ((void *)0);
	r1 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r1)
		return (NULL);
	ft_strlcpy(r1, s1, ft_strlen(s1) + 1);
	ft_strlcpy(r1 + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (r1);
}

/*
#include <stdio.h>

int main()
{
	char *str1 = "Hallo ";
	char *str2 = "Welt!";
	char *str3;

	str3 = ft_strjoin(str1, str2);
	printf("%s\n", str3);
	free(str3);
	str3 = ft_strjoin(str2, str1);
	printf("%s\n", str3);
	free(str3);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra gcc ft_strjoin.c ft_strlen.c ft_strlcpy.c
