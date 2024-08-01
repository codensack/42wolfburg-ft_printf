/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmasur <thmasur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:06 by thmasur           #+#    #+#             */
/*   Updated: 2024/06/10 12:58:06 by thmasur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_substrings(const char *s, char c);
static char	*ft_get_substrings(char const *s, char c);
static void	ft_free_substrings(char **substrings);
static void	*ft_errorhandling(char **substrings);

/*
** ft_split - A function to split a string into an array of strings.
** char const *s	: The string to be split.
** char c			: The delimiter character used to split the string.
**
** DESCRIPTION: This function takes a string 's' and a delimiter 'c',
** and splits 's' into an array of strings, where each element is a
** substring of 's' that was delimited by one or more occurrences of 'c'.
** Memory for the array is dynamically allocated and needs to be freed
** by the caller. If the allocation fails, the function returns NULL.
**
** RETURN: a Pointer to the array of split strings, or NULL if memory
** allocation fails.
*/

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	char	**r;

	if (!s)
		return (NULL);
	r = malloc((ft_count_substrings(s, c) + 1) * sizeof(char *));
	if (!r)
		return (NULL);
	tmp = r;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			*tmp = ft_get_substrings(s, c);
			if (!(*tmp))
				return (ft_errorhandling(r));
			tmp++;
		}
		while (*s != c && *s)
			s++;
	}
	*tmp = NULL;
	return (r);
}

static int	ft_count_substrings(const char *s, char c)
{
	int		counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

static char	*ft_get_substrings(char const *s, char c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*s != c && *s)
	{
		s++;
	}
	return (ft_substr(tmp, 0, s - tmp));
}

static void	ft_free_substrings(char **substrings)
{
	char	**tmp;

	tmp = substrings;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(substrings);
}

static void	*ft_errorhandling(char **substrings)
{
	ft_free_substrings(substrings);
	return (NULL);
}

/*
#include <stdio.h>

int main()
{
    char	*str1 = "hello world";
    char	*str2 = "    hello   world   ";
    char	*str3 = "hello";
    char	*str4 = "";
    char	*str5 = "    ";
    char	*str6 = "abc:def:ghi";
    char	*str7 = "abc::def:ghi";
    char	*str8 = "::abc::def::ghi::";
	int		i = 0;

    printf("Testing ft_split:\n");
    char **split1 = ft_split(str1, ' ');
    if (split1)
    {
        printf("Split1 result:\n");
		while (split1[i])
            printf("%s\n", split1[i++]);
        free(split1);
    }
	i = 0;
    char **split2 = ft_split(str2, ' ');
    if (split2)
    {
        printf("Split2 result:\n");
		while (split2[i])
            printf("%s\n", split2[i++]);
        free(split2);
    }
	i = 0;
    char **split3 = ft_split(str3, ' ');
    if (split3)
    {
        printf("Split3 result:\n");
		while (split3[i])
            printf("%s\n", split3[i++]);
        free(split3);
    }
	i = 0;
    char **split4 = ft_split(str4, ' ');
    if (split4)
    {
        printf("Split4 result:\n");
		while (split4[i])
            printf("%s\n", split4[i++]);
        free(split4);
    }
	i = 0;
    char **split5 = ft_split(str5, ' ');
    if (split5)
    {
        printf("Split5 result:\n");
		while (split5[i])
            printf("%s\n", split5[i++]);
        free(split5);
    }
	i = 0;
    char **split6 = ft_split(str6, ':');
    if (split6)
    {
        printf("Split6 result:\n");
		while (split6[i])
            printf("%s\n", split6[i++]);
        free(split6);
    }
	i = 0;
    char **split7 = ft_split(str7, ':');
    if (split7)
    {
        printf("Split7 result:\n");
		while (split7[i])
            printf("%s\n", split7[i++]);
        free(split7);
    }
	i = 0;
    char **split8 = ft_split(str8, ':');
    if (split8)
    {
        printf("Split8 result:\n");
		while (split8[i])
            printf("%s\n", split8[i++]);
			free(split8);
    }
    return (0);
}
*/

// gcc -Werror -Wall -Wextra ft_split.c ft_substr.c ft_strdup.c ft_strlen.c ft_strlcpy.c
