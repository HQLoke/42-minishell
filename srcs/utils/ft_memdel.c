/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:13:20 by hloke             #+#    #+#             */
/*   Updated: 2022/03/30 11:13:47 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Free any double pointer of any data type
//* Must typecast using (void **)
void	ft_memdel(void **ptr)
{
	int	i;

	i = 0;
	if (ptr != NULL)
	{
		while (ptr[i])
		{
			free (ptr[i]);
			i += 1;
		}
		free (ptr);
	}
}
