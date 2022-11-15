/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:36:30 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/15 16:43:37 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*new_join(char *line, char *buf)
{
	int		i;
	int		k;
	int		len;
	char	*new_line;

	i = -1;
	k = -1;
	if (!*buf)
	{
		free(line);
		return (NULL);
	}
	len = ft_strlen(line) + ft_strlen(buf);
	new_line = (char *)malloc(len + 1);
	if (!new_line)
		return (NULL);
	while (++i < ft_strlen(line))
		new_line[i] = line[i];
	while (++k < ft_strlen(buf))
		new_line[i++] = buf[k];
	new_line[i] = 0;
	free(line);
	return (new_line);
}

int	search_int(char *buf, int c)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	shift_buf(char *buf, int max)
{
	int	index;
	int	i;

	i = 0;
	index = max + 1;
	while (index < BUFFER_SIZE)
	{
		buf[i] = buf[index];
		i++;
		index++;
	}
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[1024][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	line = NULL;
	line = new_join(line, buf[fd]);
	if (search_int(buf[fd], 10) != -1)
	{
		shift_buf(buf[fd], search_int(buf[fd], 10));
		return (line);
	}
	ft_memset(buf[fd], 0, BUFFER_SIZE);
	while (read(fd, buf[fd], BUFFER_SIZE) > 0)
	{
		line = new_join(line, buf[fd]);
		if (search_int(buf[fd], 10) != -1)
		{
			shift_buf(buf[fd], search_int(buf[fd], 10));
			break ;
		}
		ft_memset(buf[fd], 0, BUFFER_SIZE);
	}
	return (line);
}
