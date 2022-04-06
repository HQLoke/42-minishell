/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:56:01 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:56:01 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*copy;

	len = ft_strlen(str) + 1;
	copy = (char *)malloc(len * sizeof (*str));
	if (copy)
		ft_memcpy(copy, str, len);
	return (copy);
}
