/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:42:14 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/15 16:43:22 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*hold;

	hold = (unsigned char *)str;
	while (n > 0)
	{
		*hold = (unsigned char)c;
		hold++;
		n--;
	}
	return (str);
}
