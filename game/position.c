/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:05:51 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/09 16:45:14 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	position(void)
{
	int		i;
	int		j;

	i = 0;
	while (g_data.cart[i])
	{
		j = 0;
		while (g_data.cart[i][j])
		{
			if (g_data.cart[i][j] == 'P')
			{
				g_data.player.pos.x = j * 64 + 32;
				g_data.player.pos.y = i * 64 + 32;
			}
			j++;
		}
		i++;
	}
}
