/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:27:27 by hloke             #+#    #+#             */
/*   Updated: 2022/02/28 09:27:28 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i <= size)
	{
		str[i] = '\0';
		i += 1;
	}
	return (str);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (s == NULL)
		return (NULL);
	subs = ft_strnew(len);
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i += 1;
	}
	return (subs);
}

static int	modify_line(int ret, char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	if (ret == 0 && *s == NULL)
		return (0);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*storage;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (storage == NULL)
		storage = ft_strnew(0);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(storage, buff);
		free(storage);
		storage = tmp;
		if (ft_strchr(storage, '\n'))
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (ret < 0)
		return (-1);
	return (modify_line(ret, &storage, line));
}
