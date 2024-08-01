/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:56:21 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:56:21 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isalpha - Check if a character is alphabetic.
** int c	: The character to be checked.
**
** DLSCRIPTION: This function checks if the character 'c' is an alphabetic
** letter. An alphabetic letter is defined as either an uppercase letter
** (A-Z) or a lowercase letter (a-z).
**
** RETURN: 1 If the character is alphabetic, 0 otherwise.
**/

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*
#include <stdio.h>

int main()
{
	printf("ft_islapha('a'): %d\n", ft_isalpha('a'));
	printf("ft_islapha('1'): %d\n", ft_isalpha('1'));
	printf("ft_islapha('_'): %d\n", ft_isalpha('_'));
	printf("ft_islapha('?'): %d\n", ft_isalpha('?'));
	printf("ft_islapha('-'): %d\n", ft_isalpha('-'));
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_isalpha.c
