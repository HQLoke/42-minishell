/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:56:17 by hloke             #+#    #+#             */
/*   Updated: 2022/03/04 21:05:10 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	i = 0;
	while (sptr >= dptr && i < len)
	{
		dptr[i] = sptr[i];
		i += 1;
	}
	while (sptr < dptr && len > 0)
	{
		dptr[len - 1] = sptr[len - 1];
		len -= 1;
	}
	return (dst);
}
