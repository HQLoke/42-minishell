/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:55:40 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:55:42 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**From Kai:
**Turns out I can put return instead of break
**My error is the &&, should've put || instead.
**|| will still compare the empty string and give diff (str1[i] - 0)
**&& will jump straight to return (0)
*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i + 1 < n && str1[i] && str2[i])
		{
			if (str1[i] != str2[i])
				break ;
			i += 1;
		}
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}
