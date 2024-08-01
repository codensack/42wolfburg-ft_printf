/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:56:11 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:56:11 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_isalnum - Check if a character is alphanumeric (a-z, A-Z, 0-9).
** int c	: The character to check.
**
** DESCRIPTION: Determines if the character 'c' is alphanumeric
** (a-z, A-Z, 0-9) according to the ASCII table.
**
** RETURN: Non-zero if 'c' is alphanumeric, 0 otherwise.
**/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
#include <stdio.h>

int main()
{
	printf("ft_isalnum('a'): %d\n", ft_isalnum('a'));
	printf("ft_isalnum('1'): %d\n", ft_isalnum('1'));
	printf("ft_isalnum('_'): %d\n", ft_isalnum('_'));
	printf("ft_isalnum('?'): %d\n", ft_isalnum('?'));
	printf("ft_isalnum('-'): %d\n", ft_isalnum('-'));
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_isalnum.c ft_isalpha.c ft_isdigit.c
