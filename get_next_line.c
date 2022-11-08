/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:00:30 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/08 17:28:40 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char    *get_next_line(int fd)
{
    static char str[100];

    /* int a = read(fd, str, 50);
    printf("bytes read 1st: %d\n", a);
    int b = read(fd, str + a, 10);
    printf("bytes read 2nd: %d\n", b); */

    int i = 0;
    while (str[i - 1] != '\n')
    {
        printf("%ld ", read(fd, str + i, 1));
        i++;
    }
    return (str);
}

int main(void)
{
    int fd = open("manual.txt", O_RDONLY, 00700);
    printf("fd nb: %d\n", fd);
    char    *s = get_next_line(fd);
    printf("string:\n%s\n", s);
    return (0);
}