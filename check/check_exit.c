/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:58:13 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/07 17:02:12 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_exit(t_graph *data)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (data->map[i])
	{
		if (data->map[i] == 'E')
			e++;
		if (e > 1)
			ft_error("ERROR!\nThe map must contain 1 exit.\n");
		i++;
	}
	if (e == 0)
		ft_error("ERROR!\nThe map must contain 1 exit.\n");
}
