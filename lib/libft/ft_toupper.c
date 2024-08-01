/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:59:33 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:59:33 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_toupper - Convert a lowercase letter to an uppercase letter.
** int c	: The character to be converted.
**
** DESCRIPTION: This function converts a lowercase letter to the
** corresponding uppercase letter. If the character is not a lowercase
** letter, it is returned unchanged.
**
** RETURN: The uppercase equivalent of the character if it is a lowercase
** letter, otherwise the character itself.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}

/*
#include <stdio.h>

int main()
{
	char a = 'a';
	char b = 'B';

	printf("Original -> a: %c, b: %c\n", a, b);
	printf("Toupper -> a: %c, b: %c\n", ft_toupper(a), ft_toupper(b));
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_toupper.c
