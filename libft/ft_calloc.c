/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:56:36 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/07 16:43:44 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*str;
	size_t	t;

	t = num * size;
	str = (void *)malloc(t);
	if (!str)
		return (NULL);
	ft_memset(str, 0, t);
	return (str);
}
