/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:02:52 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/07 17:02:12 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_player(t_graph *data)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (data->map[i])
	{
		if (data->map[i] == 'P')
			e++;
		if (e > 1)
			ft_error("ERROR!\nThe map must contain 1 Player.\n");
		i++;
	}
	if (e == 0)
		ft_error("ERROR!\nThe map must contain 1 Player.\n");
}
