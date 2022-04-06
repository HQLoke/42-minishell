/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:55:56 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:55:56 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The reason for the if check is ft_strlcat does not
**modify string
*/
int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = dlen;
	while (*src && i + 1 < dstsize)
	{
		dst[i] = *src;
		i += 1;
		src += 1;
	}
	dst[i] = '\0';
	if (dstsize <= dlen)
		return (slen + dstsize);
	return (slen + dlen);
}
