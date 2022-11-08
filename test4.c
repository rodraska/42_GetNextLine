/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:29:37 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/08 14:59:33 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
    int     fd;
    char    buf[18];
    
    //write
    
    fd = open("ficheiro.txt", O_CREAT | O_WRONLY, 00700);
    if (fd == -1)
    {
        printf("Failure 1 man...");
        exit (1);
    }

    write(fd, "Mekie mos tropaz\n", 17);
        
    close(fd);

    //read
    
    fd = open("ficheiro.txt", O_RDONLY, 00700);
    if (fd == -1)
    {
        printf("Failure 2 man...");
        exit (1);
    }
    
    read(fd, buf, 17);
    buf[17] = '\0';
    
    close (fd);

    printf("buf: %s", buf);
    
    return (0);
}