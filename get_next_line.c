/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:00:30 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/12 14:49:34 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_join(char *line, char *buf)
{
	int		i;
	int		k;
	int		len;
	char	*new_line;

	i = -1;
	k = -1;
	len = ft_strlen(line) + ft_strlen(buf);
	new_line = (char *)malloc(len + 1);
	if (!new_line)
		return (NULL);
	while (++i < ft_strlen(line))
		new_line[i] = line[i];
	while (++k < ft_strlen(buf))
		new_line[i++] = buf[k];
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
	static char	buf[BUFFER_SIZE];
	int			flag;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	flag = 0;
	if (buf[0])
		line = new_join(line, buf);
	while (read(fd, buf, BUFFER_SIZE) > 0 && flag == 0)
	{
		line = new_join(line, buf);
		if (search_int(buf, 10) != -1)
		{
			shift_buf(buf, search_int(buf, 10));
			break ;
		}
	}
	return (line);
}

/* int main(void)
{
	char	*s;
	int fd = open("manual.txt", O_RDONLY, 00700);
	printf("fd nb: %d\n", fd);
	printf("res : %s", get_next_line(fd));
	printf("res : %s", get_next_line(fd));
	printf("res : %s", get_next_line(fd));
	printf("res : %s", get_next_line(fd));
	printf("res : %s", get_next_line(fd));
	//printf("res : %s", get_next_line(fd));
	//s = get_next_line(fd);
	//printf("s: %s\n", s);
} */