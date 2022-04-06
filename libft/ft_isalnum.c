/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:56:59 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:56:59 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argument)
{
	if (argument >= 65 && argument <= 90)
		return (1);
	if (argument >= 97 && argument <= 122)
		return (1);
	if (argument >= 48 && argument <= 57)
		return (1);
	return (0);
}
