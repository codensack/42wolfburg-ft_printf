/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:59:28 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:59:28 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_tolower - Convert an uppercase letter to a lowercase letter.
** int c	: The character to be converted.
**
** Description: This function converts an uppercase letter to the
** corresponding lowercase letter. If the character is not an uppercase
** letter, it is returned unchanged.
**
** Return: The lowercase equivalent of the character if it is an uppercase
** letter, otherwise the character itself.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}

/*
#include <stdio.h>

int main()
{
	char a = 'a';
	char b = 'B';

	printf("Original -> a: %c, b: %c\n", a, b);
	printf("Tolower -> a: %c, b: %c\n", ft_tolower(a), ft_tolower(b));
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_tolower.c
