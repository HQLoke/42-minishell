/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:36 by hloke             #+#    #+#             */
/*   Updated: 2022/04/08 17:05:43 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_array_dup(char **src_array, int num_var)
{
	int		i;
	int		src_size;
	char	**tmp;
	
	i = 0;
	src_size = ft_array_size(src_array);
	if (num_var < src_size)
		num_var = src_size;
	tmp = ft_calloc(num_var + 1, sizeof(char *));
	while (i < src_size)
	{
		tmp[i] = ft_strdup(src_array[i]);
		i += 1;
	}
	return (tmp);
}
