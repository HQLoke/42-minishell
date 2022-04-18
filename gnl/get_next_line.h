/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:27:31 by hloke             #+#    #+#             */
/*   Updated: 2022/02/28 09:27:31 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

char	*ft_strchr(const char *s, int c);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strnew(size_t size);
char	*ft_strsub(char	const *s, unsigned int start, size_t len);
int		get_next_line(const int fd, char **line);

#endif