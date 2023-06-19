/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:11:22 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 21:13:07 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	var_init2(void)
{
	g_data.cart = g_data.pars.map;
	g_data.viewangle = 60 * (M_PI / 180);
	g_data.player.speedretate = SPEED_R * (M_PI / 180);
	g_data.player.speedretate_m = M_SPEED_R * (M_PI / 180);
	g_data.player.speedmove = (CUBE * SPEED_M) / 20 ;
	g_data.player.dirturn = 0;
	g_data.player.dirwalk = 0;
	g_data.rad = M_PI / 180;
}

void	var_init(void)
{
	g_data.no.img = 0;
	g_data.no.img_w = 0;
	g_data.no.img_h = 0;
	g_data.no.addr = 0;
	g_data.frame1 = 0;
	g_data.shotf = 0;
	g_data.nshot = BUL;
	g_data.nb1 = 0;
	g_data.nb2 = 0;
	g_data.nb3 = 0;
	g_data.c.r = ft_atoi(g_data.pars.c[0]);
	g_data.c.g = ft_atoi(g_data.pars.c[1]);
	g_data.c.b = ft_atoi(g_data.pars.c[2]);
	g_data.f.r = ft_atoi(g_data.pars.f[0]);
	g_data.f.g = ft_atoi(g_data.pars.f[1]);
	g_data.f.b = ft_atoi(g_data.pars.f[2]);
	g_data.f.color = rgb(g_data.f.r, g_data.f.g, g_data.f.b);
	g_data.c.color = rgb(g_data.c.r, g_data.c.g, g_data.c.b);
	var_init2();
}
