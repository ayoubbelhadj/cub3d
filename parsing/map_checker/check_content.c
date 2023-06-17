/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:44:09 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/16 23:53:21 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_existance(char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (g_data.pars.map[++i])
	{
		j = -1;
		while (g_data.pars.map[i][++j])
		{
			if (g_data.pars.map[i][j] == c)
				count++;
		}
	}
	if (!count)
		return (0);
	return (1);
}

int	player_num(void)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (g_data.pars.map[++i])
	{
		j = -1;
		while (g_data.pars.map[i][++j])
		{
			if (g_data.pars.map[i][j] == 'N' || g_data.pars.map[i][j] == 'S'
				|| g_data.pars.map[i][j] == 'E' || g_data.pars.map[i][j] == 'W')
				c++;
		}
	}
	if (c != 1)
		return (0);
	return (1);
}

int	check_content(void)
{
	int	i;
	int	j;

	i = -1;
	while (g_data.pars.map[++i])
	{
		j = -1;
		while (g_data.pars.map[i][++j])
		{
			if (g_data.pars.map[i][j] != '0' && g_data.pars.map[i][j] != '1'
				&& g_data.pars.map[i][j] != '\n' && g_data.pars.map[i][j] != 'N'
				&& g_data.pars.map[i][j] != 'S' && g_data.pars.map[i][j] != 'E'
				&& g_data.pars.map[i][j] != 'W' && g_data.pars.map[i][j] != ' ')
				return (0);
		}
	}
	if (!player_num())
		return (0);
	if (!check_existance('0') || !check_existance('1')
		|| !check_existance('\n'))
		return (0);
	return (1);
}

