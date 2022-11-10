/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:00:30 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/10 16:54:08 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_join(char *line, int max)
{
	int		i;
	int		index;
	int		len;
	char	*new_line;

	i = -1;
	index = -1;
	len = 0;
	if (line)
		//len = tirar o lenght(line)
	new_line = (char *)malloc(len + BUFFER_SIZE + 1);
	while (++i < len)
		new_line[i] = line[i];
	while (++index < BUFFER_SIZE - 1)
		new_line;
}

int	search_nl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == 10)
			return (i);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (buf[0])
		line = buf;
	read(fd, buf, BUFFER_SIZE);
	line = new_join()
	return (line);
}

int main(void)
{
	int fd = open("manual.txt", O_RDONLY, 00700);
	printf("fd nb: %d\n", fd);
	char    *s1 = get_next_line(fd);
	printf("string1:\n%s", s1);
	/* char    *s2 = get_next_line(fd);
	printf("string2:\n%s\n", s2);
	char    *s3 = get_next_line(fd);
	printf("string3:\n%s\n", s3);
	char    *s4 = get_next_line(fd);
	printf("string4:\n%s\n", s4);
	char    *s5 = get_next_line(fd);
	printf("string5:\n%s\n", s5); */
}