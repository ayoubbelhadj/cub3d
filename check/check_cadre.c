/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cadre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:10:28 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/07 17:02:12 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_x(t_graph *data, int line)
{
	int	i;

	i = 0;
	while (data->cart[line][i])
	{
		if (data->cart[line][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_y(t_graph *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data->cart[i])
	{
		len = ft_strlen(data->cart[i]) - 1;
		if (data->cart[i][0] && (data->cart[i][0] != '1'
			|| data->cart[i][len] != '1'))
			return (1);
		i++;
	}
	return (0);
}

void	check_cadre(t_graph *data)
{
	int	len;

	len = ft_tablen(data->cart) - 1;
	if (check_x(data, 0) || check_x(data, len) || check_y(data))
		ft_error("ERROR!\nThe map has to be closed.\n");
}
