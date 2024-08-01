/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:19 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:58:19 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strdup - Duplicate a string.
** const char *s: The string to be duplicated.
**
** DESCRIPTION: This function takes a string 's' and allocates memory
** to create a copy of it. The copy is created and a pointer to it is
** returned. The memory for the new string is dynamically allocated
** and should be freed by the caller. If the allocation fails, the
** function returns NULL.
**
** RETURN: A pointer to the duplicated string, or NULL if memory
** allocation fails.
*/

char	*ft_strdup(const char *s)
{
	char	*r1;
	char	*r2;

	r1 = malloc(ft_strlen(s) + 1);
	if (!r1 || !s)
		return (NULL);
	r2 = r1;
	while (*s)
		*r1++ = *s++;
	*r1 = '\0';
	return (r2);
}

/*
#include <stdio.h>

int main()
{
	char *str1 = "Hello Mr.Roboto!";
	char *str2;

	if (!(str2 = ft_strdup(str1)))
		return (1);
	printf("%s\n", str2);
	free(str2);
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_strdup.c ft_strlen.c
