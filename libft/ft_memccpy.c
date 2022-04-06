/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:56:29 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:56:30 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;
	size_t				i;

	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dptr[i] = sptr[i];
		if (sptr[i] == (unsigned char) c)
			return (&dptr[i + 1]);
		i += 1;
	}
	return (0);
}
