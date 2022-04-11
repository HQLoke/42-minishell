/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:07:51 by hloke             #+#    #+#             */
/*   Updated: 2022/04/11 15:25:19 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_array_add(char **src_array, char *str)
{
	int		size;
	char	**tmp;

	size = 0;
	if (src_array == NULL)
		tmp = ft_calloc(2, sizeof(char *));
	else
	{
		size = ft_array_size(src_array);
		tmp = ft_array_dup(src_array, size + 1);
		ft_memdel((void **)src_array);
	}
	tmp[size] = ft_strdup(str);
	return (tmp);
}
