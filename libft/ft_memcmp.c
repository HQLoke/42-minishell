/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:56:27 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:56:27 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	if (n > 0)
	{
		ptr1 = (unsigned char *)str1;
		ptr2 = (unsigned char *)str2;
		i = 0;
		while (i + 1 < n)
		{
			if (ptr1[i] != ptr2[i])
				break ;
			i += 1;
		}
		return (ptr1[i] - ptr2[i]);
	}
	return (0);
}
