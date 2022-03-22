/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:31:59 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/21 13:33:31 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# define H 800
# define W 800

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_point;

typedef struct s_params
{
	int		zoom;
	double	angle_x;
	double	angle_y;
	int		tran_x;
	int		tran_y;
	float 	kz;
	int 	default_color;
}					t_params;

typedef struct s_mouse
{
	int	is_mouse_down;
	int	x;
	int	y;
}					t_mouse;

typedef struct s_coord
{
	int	z;
	int	color;
	int	color_defined;
}			t_coord;

typedef struct s_base
{
	t_params	params;
	t_mouse		mouse;
	t_coord		***matrix;
	int			sum_coord;
	int			size_x;
	int			size_y;
	int			max;
	int			min;
	int			color_change;
	int			color_detected;

	void		*mlx;
	void		*mlx_win;

	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}			t_base;

//general
void	render(t_base *base);
char	*del_ln(char *s);
t_point	*create_point(t_base *base, int x, int y);

//math
float	ft_max(float a, float b);
long	ft_mod(int a);
int		ft_inwin_x(float a);
int		ft_inwin_y(float a);
void	max_in_matrix(t_base *base);
int		atoi_hex(char *s, int *f);
int		is_duplicate(int k);

//draw
void	my_mlx_pixel_put(t_base *data, int x, int y, int color);
void	draw(t_base *base);
int		create_color(int c1, int c2, float prc);
int		color_from_coords(t_base *base, int x, int y);

//color_utils
int		create_trgb(int t, int r, int g, int b);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

//params
void	zoom_coords(t_base *base, t_point *p1, t_point *p2);
void	trans_coords(t_base *base, t_point *p1, t_point *p2);
void	trans_coords_con(t_point *p1, t_point *p2, int x, int y);
void	rotate(t_point *p, t_base *r);

//keyhook
int		key_hook(int keycode, t_base *base);
int		mouse_down(int button, int x, int y, t_base *base);
int		mouse_up(int button, int x, int y, t_base *base);
int		mouse_move(int x, int y, t_base *base);
void	zoom(int key, t_base *base);
void	trans(int key, t_base *base);
void	koef_z(int key, t_base *base);
void	project(int key, t_base *base);
void	angle(int key, t_base *base);
int		expose(t_base *base);

//parse
void	parse(t_base *base, char *file_path);
int		valid_map(char *file_path);

//errors
void	error_exit(char *s);
void	exit_errno(void);

//free
void	free_all(t_base *base);
void	free_matrix(t_base *base);
void	free_split(char **arr);

#endif
