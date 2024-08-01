/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:25 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:58:25 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_striteri - This function applies function "f" on each character of
** char *s							: The string to iterate over.
** void (*f)(insigned int, char *)	: The function to apply to each character.
**
** DESCRIPTION: The function ft_striteri iterates over a string and applies
** a given function to each character of the string.
**
** RETURN: None.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		while (*(s + i))
		{
			f(i, s + i);
			i++;
		}
	}
}

/*
#include <stdio.h>

void	to_upper(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= (32 + i - i);
}

int main()
{
	char s[] = "hello, world";
	printf("The string is: %s\n", s);
	ft_striteri(s, to_upper);
	printf("The string is now: %s\n", s);
	return (0);	
}
*/

// gcc -Werror -Wall -Wextra ft_striteri.c
