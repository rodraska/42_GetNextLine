/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:05:39 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/07 15:21:58 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char    text[50];
    printf("Enter your text here: ");
    fgets(text, 50, stdin);
    printf("This is the your text: %s", text);
    printf("This is the text length: %ld\n", strlen(text));
    //text[strlen(text) - 1] = '\0';
    int i = 0;
    while (i <= strlen(text))
    {
        printf("%d ", text[i]);
        i++;
    }
    return (0);
}