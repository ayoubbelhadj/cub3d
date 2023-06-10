/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:58:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/10 15:30:31 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < g_data.x_width) && (y >= 0 && y < g_data.y_height))
	{
		dst = g_data.addr + ((y * g_data.line_length) + \
		(x * (g_data.bits_per_pixel / 8)));
		*(unsigned int *)dst = color;
	}
}
void drawCircle(int xc, int yc, int radius)
{
	int	y;
	int	x;
	
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
                my_mlx_pixel_put(xc + x, yc + y, 0xFF0000); // Draw pixels in white
			x++;
		}
		y++;
	}
}

void draw_line(int x1, int y1, int x2, int y2, int line_width)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2)
    {
        for (int i = 0; i < line_width; i++)
        {
            for (int j = 0; j < line_width; j++)
            {
                my_mlx_pixel_put(x1 + i, y1 + j, 0x3333FF);
            }
        }
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void	fillmap(void)
{
	int	i;
	int	j;
	int	x;
	int y;
	int color;

	i = 0;
	i = 0;
	while (g_data.cart[i])
	{
		j = 0;
		while (g_data.cart[i][j])
		{
			if (g_data.cart[i][j] == '1')
				color = 0x000000;
			else
				color = 0xFFFFCC;
			x = 0;
			while (x < 64)
			{
				y = 0;
				while (y < 64)
				{
					my_mlx_pixel_put(j * 64 + x, i * 64 + y, color);
					y++;
				}
				x++;
			}
			j++;
		}
		i++;
	}
}

void	addimg(void)
{
	fillmap();
	drawCircle(g_data.player.pos.x, g_data.player.pos.y, 3);
	draw_line(g_data.player.pos.x , g_data.player.pos.y , g_data.player.pos.x + cos(g_data.player.anglerete) * 30,
			g_data.player.pos.y + sin(g_data.player.anglerete) * 30 , 1);
}
 