/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:57:05 by jcapistr          #+#    #+#             */
/*   Updated: 2022/12/03 10:57:05 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *buf, char *new_buf)
{
	char	*tmp;

	if (buf == NULL)
	{
		buf = (char *)ft_calloc(sizeof(char), 1);
		if (buf == NULL)
			return (NULL);
	}
	tmp = (char *)ft_calloc(sizeof(char), ft_strlen(buf) + ft_strlen(new_buf)
			+ 1);
	if (tmp == NULL)
		return (NULL);
	ft_memcpy(tmp, buf, ft_strlen(buf));
	ft_memcpy(tmp + ft_strlen(buf), new_buf, ft_strlen(new_buf));
	free(buf);
	return (tmp);
}

static char	*ft_read(int fd, char *buf)
{
	char	*new_buf;
	int		bytes;

	new_buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (new_buf == NULL)
		return (NULL);
	bytes = 42;
	while (ft_strchr(buf, '\n') == NULL && bytes != 0)
	{
		bytes = (int)read(fd, new_buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			free(new_buf);
			return (NULL);
		}
		buf = ft_join(buf, new_buf);
	}
	free(new_buf);
	return (buf);
}

static char	*ft_line(const char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (buf[i] == '\0')
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	line = (char *)ft_calloc(sizeof(char), i + 2);
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, buf, i);
	if (buf[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*ft_move(char *buf)
{
	char	*tmp;
	int		i;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	tmp = ft_strdup(buf + (++i));
	if (tmp == NULL)
		return (NULL);
	free(buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (buf == NULL)
		return (NULL);
	line = ft_line(buf);
	buf = ft_move(buf);
	return (line);
}
