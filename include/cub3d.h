/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:47:12 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 01:04:47 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"

# define CUBE 10
# define WIN_W 1020
# define WIN_H 800
# define BAR_W 1020
# define BAR_H 200
# define SPEED_R 5
# define M_SPEED_R 1
# define SPEED_M 2

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_g3d
{
	double	disproj;
	double	disprojfix;
	double	projwallh;
	int		wbwh;
	int		walltop;
	int		wallbottom;
	int		x;
	int		y;
}			t_g3d;

typedef struct s_pars
{
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	*colorf;
	char	*colorc;
	char	**f;
	char	**c;
	char	**map;
	char	pos;
	int		x;
	int		y;
}				t_pars;

typedef struct s_ray
{
	double	angle;
	double	dis;
	double	x;
	double	y;
	int		up;
	int		down;
	int		left;
	int		right;
	double	hwallx;
	double	hwally;
	double	vwallx;
	double	vwally;
	double	hdis;
	double	vdis;
	int		iswallh;
	int		iswallv;
	double	hx;
	double	hy;
	double	hxstep;
	double	hystep;
	double	hxnext;
	double	hynext;
	double	vx;
	double	vy;
	double	vxstep;
	double	vystep;
	double	vxnext;
	double	vynext;
	int		v;
	int		h;
}			t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	dirturn;
	double	dirwalk;
	double	dirwalkx;
	double	alpha;
	double	speedmove;
	double	speedretate;
	double	speedretate_m;
}		t_player;

typedef struct s_texture
{
	void			*img;
	int				img_w;
	unsigned int	*addr;
	int				img_h;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}		t_texture;

typedef struct s_img
{
	void			*img;
	int				img_w;
	char			*addr;
	int				img_h;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}			t_img;

typedef struct s_sprite
{
	void	*img;
	char	*path;
}		t_sprite;

typedef struct s_data
{
	t_player	player;
	char		*addr;
	char		**cart;
	char		*map;
	void		*mlx;
	char		*mlx_win;
	int			x_width;
	int			y_height;
	int			endian;
	int			dgame;
	double		viewangle;
	int			nbr_rays;
	double		*rays;
	double		rad;
	int			xmouse;
	t_g3d		*g3d;
	t_ray		*ray;
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	t_img		img;
	t_img		img2;
	t_img		img3;
	t_img		img4;
	t_sprite	*gun;
	t_sprite	*nbr;
	int			flag;
	int			shotf;
	int			frame1;
	void		*gunp;
	t_pars		pars;
}			t_data;
t_data		g_data;

/* check */
int		check_wall(double x, double y);
int		is_wall(double x, double y);
int		isdown(double angle);
int		isright(double angle);
void	vapsangle(double *angle);
void	turn_left(int flag);
void	turn_right(int flag);

/* draw */
void	my_mlx_pixel_put(int x, int y, int color);
void	my_mlx_pixel_put2(int x, int y, int color);
void	my_mlx_pixel_put3(int x, int y, int color);
void	drawcircle(int xc, int yc, int radius);
void	line(double dis, double ang, int color);
void	fillmap(void);
void	drawrays(void);
int		rgb(int r, int g, int b);

/* ray */
void	sendrays(void);
void	h_cast(int i);
void	v_cast(int i);
double	distance(double x, double y);
void	h_return(int i, double dis);
void	v_return(int i, double dis);

/* game */
int		update(void);
void	game(void);
void	position(void);
int		quit(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	move_top(t_data *data);
void	addimg(void);
int		keys(int key, t_data *data);
int		mouse(int x);

/* 3D*/
void	g3d(void);
void	rend3d(void);
void	img3d(void);

/* init*/
void	imgs_init(void);
void	win_init(void);
void	wall_init(void);
void	init(void);
void	resetimg(void);

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
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
int		ft_tablen(char **tab);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

/*parser*/
int		parsing(char *str);
int		dot_cub(char *arg);
int		all_white(char *str);
int		check_lines(char *str);
char	*get_line(char **tab, char *str);
char	*rest_of_line(char *line, char *str);
char	*get_str(char *str);
int		check_colors(void);
int		accessible(void);
char	**file_tab(char *str);
char	**fst_part(char **tab);
int		checker_map1(char *str);
int		lines_number(char *str);
int		check_content(void);
void	printerr(int e);
void	player_pos(void);
int		end(char **file, char *str);
int		map_len(void);
int		check_first_last(void);

#endif