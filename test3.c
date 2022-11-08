/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:00:58 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/08 15:01:46 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    FILE *fp;

    fp = fopen("documento.txt", "w+");
    if (fp == NULL)
        return (1);
    fprintf(fp, "%s %s %d\n", "Hello", "People", 42);
    
    char str[] = "Welcome to our school!\n";
    fwrite(str, 1, sizeof(str) - 1, fp);

    fclose(fp);
    return (0);
}