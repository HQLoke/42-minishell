/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:56:05 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:56:05 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_split(char check, char c)
{
	return (check == c || check == '\0');
}

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] == c)
		i += 1;
	while (s[i])
	{
		if (s[i] != c && is_split(s[i + 1], c))
			count += 1;
		i += 1;
	}
	return (count);
}

static char	*create_word(char const *s, int len)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i += 1;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	array = malloc(sizeof (char *) * (count_word(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		j = 0;
		while (!is_split(*(s + j), c))
			j += 1;
		if (j)
		{
			array[i++] = create_word(s, j);
			s += j;
		}
		else
			s += 1;
	}
	array[i] = NULL;
	return (array);
}
