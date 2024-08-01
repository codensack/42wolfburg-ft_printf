/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:56:53 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:56:53 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_char_count(int n);

/*
** ft_itoa - Converts an integer to a null-terminated string.
** int n	: The integer to be converted.
**
** DESCRIPTION: This function takes an integer 'n' and converts it to a string
** representation. Memory for the resulting string is dynamically allocated
** and needs to be freed by the caller. If the allocation fails, the function
** returns NULL. The function handles both positive and negative integers.
**
** RETURN: A Pointer to the resulting null-terminated string, or NULL if memory
** allocation fails.
*/

char	*ft_itoa(int n)
{
	char	*r;
	int		i;

	i = ft_get_char_count(n);
	r = malloc(i);
	if (!r)
		return (NULL);
	*(r + --i) = '\0';
	if (n == 0)
		*(r + --i) = '0';
	else if (n < 0)
		*r = '-';
	while (n)
	{
		if (n < 0)
			*(r + --i) = -(n % 10) + '0';
		else
			*(r + --i) = (n % 10) + '0';
		n = n / 10;
	}
	return (r);
}

static int	ft_get_char_count(int n)
{
	int	counter;

	counter = 1;
	if (n <= 0)
		counter++;
	while (n)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

/*
#include <stdio.h>

int main()
{
	int	num = -2147483648;
	char *str;

	printf("The number is %d\n", num);
	if ((str = ft_itoa(num)))
	{
		printf("ft_itoa: %s\n", str);
		free(str);
	}
	num = 2147483647;
	printf("The number is %d\n", num);
	if ((str = ft_itoa(num)))
	{
		printf("ft_itoa: %s\n", str);
		free(str);
	}
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_itoa.c
