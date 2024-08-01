/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:54 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:58:54 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strmapi - Apply a function to each character of a string.
** char const *s					: The input string.
** char (*f)(unsigned int, char)	: The function to apply to each character.
**
** DESCRIPTION: Applies the function 'f' to each character of the string 's',
** passing the character's index as the first argument to 'f', and creates a new
** string with the results. The new string is dynamically allocated and must be
** freed by the caller.
**
** RETURN: A pointer to the new string, or NULL if memory allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r1;
	char			*r2;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	r1 = malloc(ft_strlen(s) + 1);
	if (!r1)
		return (NULL);
	r2 = r1;
	i = 0;
	while (*(s + i))
	{
		*r1++ = (*f)(i, *(s + i));
		i++;
	}
	*r1 = '\0';
	return (r2);
}

/*
#include <stdio.h>

char	ft_transform(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (ft_toupper(c));
	else
		return (ft_tolower(c));
	return (c);
}

int main()
{
	char original[] = "hello, world!";
	char *transformed = ft_strmapi(original, ft_transform);
	if (transformed)
	{
		printf("The original string is: %s\n", original);
		printf("The transformed string: is %s\n", transformed);
		free(transformed);
	}
}
*/

// gcc -Werror -Wall -Wextra ft_strmapi.c ft_strlen.c ft_toupper.c ft_tolower.c
