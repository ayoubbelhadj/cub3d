/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:45:04 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/16 23:52:35 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	map_len(void)
{
	int	i;

	i = 0;
	while (g_data.pars.map[i])
		i++;
	return (i);
}

int	check_first_last(void)
{
	int	i;
	int	e;

	i = -1;
	while (g_data.pars.map[0][++i])
	{
		if (g_data.pars.map[0][i] == '0'
			|| g_data.pars.map[0][i] == g_data.pars.pos)
			return (0);
	}
	e = map_len() - 1;
	i = -1;
	while (g_data.pars.map[e][++i])
	{
		if (g_data.pars.map[e][i] == '0'
			|| g_data.pars.map[e][i] == g_data.pars.pos)
			return (0);
	}
	return (1);
}
