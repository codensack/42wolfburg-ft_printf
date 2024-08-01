/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:56:37 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:56:37 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isdigit - Check if a character is a digit (0-9)
** int c	: The character to check.
**
** DESCRIPTION: Determines if the character 'c' is a digit (0-9) according to
** the ASCII table.
**
** RETURN: 1 if 'c' is a digit, 0 otherwise.
**/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
#include <stdio.h>

int main()
{
	printf("ft_isdigit('a'): %d\n", ft_isdigit('a'));
	printf("ft_isdigit('1'): %d\n", ft_isdigit('1'));
	printf("ft_isdigit('_'): %d\n", ft_isdigit('_'));
	printf("ft_isdigit('?'): %d\n", ft_isdigit('?'));
	printf("ft_isdigit('-'): %d\n", ft_isdigit('-'));
	printf("ft_isdigit('9'): %d\n", ft_isdigit('9'));
	printf("ft_isdigit('0'): %d\n", ft_isdigit('0'));
    return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_isdigit.c
