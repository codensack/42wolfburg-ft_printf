/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:54:51 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:54:51 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace_char(char c);

/*
** ft_atoi - Converts a string to an integer.
** const char *nptr	: The string to be converted.
**
** DESCRIPTION: The pointer 'nptr' points to a string that should be
** converted into an integer. The function discards any whitespace characters
** until it founds an (optional) plus or minus sign followed by as many
** numerical digits as possible, and interprets them as an integer. If no
** no valid integer is found, the function returns 0
**
** RETURN: The converted integer, or 0 in error case.
*/

int	ft_atoi(const char *nptr)
{
	int	r;
	int	sign;

	r = 0;
	sign = 1;
	while (ft_is_whitespace_char(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		r = r * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * r);
}

static int	ft_is_whitespace_char(char c)
{
	int	r;

	r = 0;
	if (c == ' ' || c == '\t' || c == '\n')
		r = 1;
	else if (c == '\f' || c == '\r' || c == '\v')
		r = 1;
	return (r);
}

/*
#include <stdio.h>

int main()
{
	printf("ft_atoi(\"42\"): %d\n", ft_atoi("42"));
	printf("atoi(\"42\"): %d\n", atoi("42"));
	printf("ft_atoi(\"+42\"): %d\n", ft_atoi("+42"));
	printf("atoi(\"+42\"): %d\n", atoi("+42"));
	printf("ft_atoi(\"-42\"): %d\n", ft_atoi("-42"));
	printf("atoi(\"-42\"): %d\n", atoi("-42"));
	printf("ft_atoi(\"-0\"): %d\n", ft_atoi("-0"));
	printf("atoi(\"-0\"): %d\n", atoi("-0"));
	printf("ft_atoi(\"+0\"): %d\n", ft_atoi("+0"));
	printf("atoi(\"+0\"): %d\n", atoi("+0"));
	printf("ft_atoi(\"    42\"): %d\n", ft_atoi("    42"));
	printf("atoi(\"    42\"): %d\n", atoi("    42"));
	printf("ft_atoi(\"42    \"): %d\n", ft_atoi("42    "));
	printf("atoi(\"42    \"): %d\n", atoi("42    "));
	printf("ft_atoi(\"   -42\"): %d\n", ft_atoi("   -42"));
	printf("atoi(\"   -42\"): %d\n", atoi("   -42"));
	printf("ft_atoi(\"-42    \"): %d\n", ft_atoi("-42    "));
	printf("atoi(\"-42    \"): %d\n", atoi("-42    "));
	printf("ft_atoi(\"42__nondigits\"): %d\n", ft_atoi("42_nondigits"));
	printf("atoi(\"42_nondigits\"): %d\n", atoi("42_nondigits"));
	printf("ft_atoi(\"Nondigits_and_42\"): %d\n", ft_atoi("Nondigits_and_42"));
	printf("atoi(\"Nondigits_and_42\"): %d\n", atoi("Nondigits_and_42"));
	printf("ft_atoi(\"-91283472332\"): %d\n", ft_atoi("-91283472332"));
	printf("atoi(\"-91283472332\"): %d\n", atoi("-91283472332"));
	printf("ft_atoi(\"+\"): %d\n", ft_atoi("+"));
	printf("atoi(\"+\"): %d\n", atoi("+"));
	printf("ft_atoi(\"-\"): %d\n", ft_atoi("-"));
	printf("atoi(\"-\"): %d\n", atoi("-"));
	printf("ft_atoi(\"\" (empty string): %d\n", ft_atoi(""));
	printf("atoi(\"\" (empty string): %d\n", atoi(""));
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_atoi.c ft_isdigit.c
