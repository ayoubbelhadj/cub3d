/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:05:51 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 01:20:54 by abelhadj         ###   ########.fr       */
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
			if (g_data.cart[i][j] == 'N' || g_data.cart[i][j] == 'S'
				|| g_data.cart[i][j] == 'E' || g_data.cart[i][j] == 'W')
			{
				g_data.player.x = j * CUBE + CUBE / 2;
				g_data.player.y = i * CUBE + CUBE / 2;
			}
			j++;
		}
		i++;
	}
}
