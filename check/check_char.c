/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:09:52 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/07 17:02:12 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_char(t_graph *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	i = 0;
	while (data->cart[i])
	{
		j = 0;
		while (data->cart[i][j])
		{
			c = data->cart[i][j];
			if (c != '0' && c != '1' && c != 'C'
				&& c != 'E' && c != 'P')
			{
				ft_error("ERROR!!\nThe map can be composed of only these 5 characters: \
{0,1,E,C,P}.\n");
			}
			j++;
		}
		i++;
	}
}
