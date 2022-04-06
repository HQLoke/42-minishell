/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:15:12 by hloke             #+#    #+#             */
/*   Updated: 2022/03/21 15:18:26 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_array_size(char **array)
{
	size_t	num;

	num = 0;
	if (array != NULL)
	{
		while (array[num] != NULL)
			num += 1;
	}
	return (num);
}
