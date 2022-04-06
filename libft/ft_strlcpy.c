/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:55:53 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:55:54 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**src[i] must be true, coz need to copy from non-empty src
*/
int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{	
		while (i + 1 < size && src[i])
		{
			dst[i] = src[i];
			i += 1;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
