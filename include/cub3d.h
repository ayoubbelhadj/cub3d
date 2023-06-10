/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:47:12 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/09 17:35:02 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "mlx.h"

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_player
{
	t_pos	pos;
	double	rad;
	double	dirturn;
	double	dirwalk;
	double	anglerete;
	double	speedmove;
	double	speedretate;
}		t_player;

typedef struct s_graph
{
	t_pos	player;
	t_pos	exit;
	char	**cart;
	char	*map;
	int		x_width;
	int		y_height;
	int		move_cpt;
	void	*mlx;
	char	*mlx_win;
	void	*wall;
	void	*floor;
	void	*p_front;
	void	*p_back;
	void	*p_left;
	void	*p_right;
	void	*stone;
	void	*portal;
	void	*portal_open;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_graph;

typedef struct s_data
{
	t_player	player;
	void		*img;
	char		*addr;
	char		**cart;
	char		*map;
	void		*mlx;
	char		*mlx_win;
	int			x_width;
	int			y_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}			t_data;
t_data		g_data;

/* check */
void	check_map(t_graph *data);
void	check_char(t_graph *data);
void	check_cadre(t_graph *data);
void	check_coin(t_graph *data);
void	check_exit(t_graph *data);
void	check_player(t_graph *data);
void	check_rect(t_graph *data);
void	check_path(t_graph *data, int base);

/* game */
void	game(void);
void	position(void);
int		quit(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	move_top(t_data *data);
void	img_path(t_graph *data);
void	addimg(void);
int		keys(int key, t_data *data);

/* utils */
char	*read_map(int fd);
void	ft_error(char *msg);
int		name_check(char *name);
char	**split_map(char *map);
void	free_cart(char **p);

/* libft */
void	*ft_calloc(size_t num, size_t size);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
int		ft_tablen(char **tab);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif