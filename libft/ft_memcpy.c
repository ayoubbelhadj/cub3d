/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:38:59 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/07 16:43:44 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cd;
	unsigned char	*cs;

	if (!dest && !src)
		return (0);
	i = 0;
	cd = (unsigned char *)dest;
	cs = (unsigned char *)src;
	while (i < n)
	{
		cd[i] = cs[i];
		i++;
	}
	return (dest);
}
