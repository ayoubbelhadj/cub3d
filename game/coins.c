/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:51:59 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/07 17:00:11 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	coins(t_graph *data)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	cpt = 0;
	while (data->cart[i])
	{
		j = 0;
		while (data->cart[i][j])
		{
			if (data->cart[i][j] == 'C')
				cpt++;
			j++;
		}
		i++;
	}
	return (cpt);
}
