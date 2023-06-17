/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:32:26 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/16 23:50:22 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_read(int fd, char *buffer, char *t)
{
	int	i;

	i = 1;
	while (i)
	{
		i = read(fd, buffer, 1);
		if (i == -1)
		{
			if (t)
				(free(t), t = NULL);
			return (NULL);
		}
		buffer[i] = 0;
		t = ft_strjoin_frees1(t, buffer);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	if (t[0] == 0)
	{
		free(t);
		t = NULL;
		return (NULL);
	}
	return (t);
}

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(i + 2);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	line[i + 1] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*read;
	char	*line;

	line = NULL;
	buffer = malloc(2);
	read = ft_read(fd, buffer, line);
	free(buffer);
	line = ft_line(read);
	free(read);
	return (line);
}
