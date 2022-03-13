/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:06:02 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/13 12:35:25 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	start_init(t_base *base)
{
	int	min;

	base->params.zoom = 15;
	base->params.angle_x = 0.0;
	base->params.angle_y = 0.0;
	base->params.tran_x = (W / 2) - (base->size_x * base->params.zoom) / 2;
	base->params.tran_y = (H / 2) - (base->size_y * base->params.zoom) / 2;
	base->mouse.is_mouse_down = 0;
	base->proj = 2;
	min = base->min;
	base->sum_coord = 0;
	while (min++ != base->max)
		base->sum_coord++;
}

int	main(int argc, char *argv[])
{
	t_base	*base;

	if (argc != 2)
		write(1, "usage: ./fdf \"map_file.fdf\"", 26);
	if (argc != 2)
		exit(0);
	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
		error_exit("Error malloc");
	base->color_detected = 0;
	parse(base, argv[1]);
	start_init(base);

//	int i;
//	int j;
//	i = 0;
//	while (i < base->size_y)
//	{
//		j = 0;
//		while (j < base->size_x)
//		{
//			printf("%-3d ", base->matrix[i][j]->z);
//			j++;
//		}
//		printf("\n");
//		i++;
//	}

	base->mlx = mlx_init();
	base->mlx_win = mlx_new_window(base->mlx, W, H, "FdF");
	render(base);
	mlx_hook(base->mlx_win, 4, (1L << 2), &mouse_down, base);
	mlx_hook(base->mlx_win, 5, (1L << 3), &mouse_up, base);
	mlx_hook(base->mlx_win, 6, (1L << 6), &mouse_move, base);
	mlx_key_hook(base->mlx_win, key_hook, base);
//	mlx_expose_hook(base->mlx_win, exposex, base);
	mlx_hook(base->mlx_win, 17, 0, expose, base);
	mlx_loop(base->mlx);
}

//
//typedef struct	s_data {
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		endian;
//}				t_data;
//
//void	my_mlx_pixel_put2(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}
//
//int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win;
//	t_data	img;
//
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								 &img.endian);
////	my_mlx_pixel_put2(&img, 5, 5, 0x00FF0000);
//	int i;
//	i = 0;
//	while (i < 1000)
//	{
//		my_mlx_pixel_put2(&img, i, i, create_trgb(255, 255, 0, 0));
//		i++;
//	}
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
//}