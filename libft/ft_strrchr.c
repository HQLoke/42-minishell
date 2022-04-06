/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:55:36 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:55:37 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*tmp;

	tmp = 0;
	while (*str)
	{
		if (*str == c)
			tmp = (char *)str;
		str += 1;
	}
	if (tmp != 0)
		return (tmp);
	if (c == '\0')
		return ((char *)str);
	return (0);
}
