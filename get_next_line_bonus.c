/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:33:02 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/12 14:38:17 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[1024][BUFFER_SIZE + 1];
	int			i;
	int			j;
	int			f;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	line = NULL;
	f = 0;
	while (!f && (buf[fd][0] || read(fd, buf[fd], BUFFER_SIZE) > 0))
	{
		line = ft_strjoin(line, buf[fd]);
		i = 0;
		j = 0;
		while (buf[fd][i])
		{
			if (f)
				buf[fd][j++] = buf[fd][i];
			if (buf[fd][i] == 10)
				f = 1;
			buf[fd][i++] = 0;
		}
	}
	return (line);
}
