/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmaxlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:05:13 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 21:05:31 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_tabmaxlen(char **map)
{
	size_t	len;
	int		i;
	size_t	len1;

	len = 0;
	i = 0;
	while (map[i])
	{
		len1 = strlen(map[i]);
		if (len < len1)
		{
			len = len1;
		}
		i++;
	}
	return (len);
}
