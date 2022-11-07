/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:11:43 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/07 14:25:27 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int add(int y)
{
    static int soma;
    
    soma = y;
    soma += 10;
    return (soma);
}

int mult(int x)
{
    static int multi = 1;
    
    multi *= x;
    return (multi);
}

int main(void)
{
    mult(5);
    printf("%d\n", add(mult(4)));
    return (0);
}

