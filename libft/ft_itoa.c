/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:56:45 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:57:24 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(long long n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		ret += 1;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	int				i;
	unsigned int	num;

	if (n >= 0)
		num = n;
	else
		num = n * -1;
	if (n >= 0)
		i = numlen(n);
	else
		i = numlen(n) + 1;
	ptr = malloc(sizeof (*ptr) * i + 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	while (--i >= 0)
	{
		ptr[i] = 48 + (num % 10);
		num /= 10;
	}
	if (n < 0)
		ptr[0] = 45;
	return (ptr);
}
