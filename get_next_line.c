/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:00:30 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/11 18:01:44 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_join(char *line, char *buf, int max)
{
	int		i;
	int		index;
	int		len;
	char	*new_line;

	i = -1;
	index = -1;
	len = 0;
	if (max == -1)
		max = BUFFER_SIZE;
	if (line[0])
		len = ft_strlen(line);
	new_line = (char *)malloc(len + max + 1);
	if (!new_line)
		return (NULL);
	while (++i < len)
		new_line[i] = line[i];
	while (++index <= max)
		new_line[i++] = buf[index];
	new_line[i] = 0;
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
	while (index < 10)
	{
		buf[i] = buf[index];
		i++;
		index++;
	}
	while (i < 10)
	{
		buf[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE];
	int			max;
	int			cread;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (*line)
		free(line);
	
	printf("line begin :%s\n", line);
	if (buf[0])
	{
		max = search_int(buf, 0);
		line = new_join(line, buf, max);
	}
	while (1)
	{
		cread = read(fd, buf, BUFFER_SIZE);
		if (cread < BUFFER_SIZE)
		{
			new_join(line, buf, cread - 1);
			break ;
		}
		max = search_int(buf, 0);
		if (max >= 0)
		{
			new_join(line, buf, max);
			break ;
		}
		printf("ola\n");
		max = search_int(buf, 10);
		line = new_join(line, buf, max);
		if (max >= 0)
		{
			shift_buf(buf, max);
			break ;
		}
	}
	printf("line end :%s", line);
	printf("rest buf :%s\n\n", buf);
	return (line);
}

int main(void)
{
	int fd = open("manual.txt", O_RDONLY, 00700);
	printf("fd nb: %d\n", fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
