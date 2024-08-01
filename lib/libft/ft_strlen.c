/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:49 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:58:49 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strlen - Calculate the length of a string.
** const char *s	: The string to calculate the length of.
**
** DESCRIPTION: This function takes a string 's' and returns its
** length, not including the terminating null byte ('\0'). The function
** iterates through the string until it encounters the null byte.
**
** Return: The length of the string.
*/

size_t	ft_strlen(const char *s)
{
	const char	*ptr_s;

	ptr_s = s;
	while (*ptr_s)
		ptr_s++;
	return (ptr_s - s);
}

/*
#include <stdio.h>

int main()
{
	char *str = "This string is 42 long!!!!!!!!!!!!!!!!!!!!";

	printf("%s\n", str);
	printf("%zu is right\n", ft_strlen(str));
	return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_strlen.c
