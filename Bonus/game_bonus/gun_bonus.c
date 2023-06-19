/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:00:09 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 17:48:57 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	frame_shut(void)
{
	g_data.frame1++;
	if (g_data.frame1 <= 3)
		g_data.gunp = g_data.gun[0].img;
	else if (g_data.frame1 <= 6)
		g_data.gunp = g_data.gun[1].img;
	else if (g_data.frame1 <= 9)
		g_data.gunp = g_data.gun[2].img;
	else if (g_data.frame1 <= 12)
		g_data.gunp = g_data.gun[3].img;
	else if (g_data.frame1 <= 15)
		g_data.gunp = g_data.gun[4].img;
	else if (g_data.frame1 <= 18)
		g_data.gunp = g_data.gun[5].img;
	else if (g_data.frame1 > 18)
	{
		g_data.frame1 = -1;
		g_data.shotf = 0;
	}
	if (g_data.frame1 == -1)
		g_data.nshot--;
}

void	frame_gun(void)
{
	g_data.frame1++;
	if (g_data.frame1 <= 3)
		g_data.minigunp = g_data.minigun[0].img;
	else if (g_data.frame1 <= 6)
		g_data.minigunp = g_data.minigun[1].img;
	else if (g_data.frame1 <= 9)
		g_data.minigunp = g_data.minigun[2].img;
	else if (g_data.frame1 <= 12)
		g_data.minigunp = g_data.minigun[3].img;
	else if (g_data.frame1 <= 15)
		g_data.minigunp = g_data.minigun[4].img;
	if (!g_data.nshot)
		g_data.minigunp = g_data.minigun[5].img;
}

void	gun_shut(void)
{
	if (g_data.shotf && g_data.nshot)
	{
		frame_shut();
		frame_gun();
	}
	else
		g_data.gunp = g_data.gun[0].img;
}

void	nbr_bullet(void)
{
	if (g_data.nshot > 99)
	{
		g_data.nb1 = g_data.nbr[g_data.nshot / 100].img;
		g_data.nb2 = g_data.nbr[(g_data.nshot % 100) / 10].img;
		g_data.nb3 = g_data.nbr[(g_data.nshot % 100) % 10].img;
	}
	else if (g_data.nshot > 9)
	{
		g_data.nb1 = g_data.nbr[0].img;
		g_data.nb2 = g_data.nbr[g_data.nshot / 10].img;
		g_data.nb3 = g_data.nbr[g_data.nshot % 10].img;
	}
	else
	{
		g_data.nb1 = g_data.nbr[0].img;
		g_data.nb2 = g_data.nbr[0].img;
		g_data.nb3 = g_data.nbr[g_data.nshot].img;
	}
}
