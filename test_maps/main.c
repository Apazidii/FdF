/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:06:02 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/22 14:55:06 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

void	start_init(t_base *base)
{
	int	min;

	base->params.zoom = 15;
	base->params.angle_x = 0.0;
	base->params.angle_y = 0.0;
	base->params.tran_x = (W / 2) - (base->size_x * base->params.zoom) / 2;
	base->params.tran_y = (H / 2) - (base->size_y * base->params.zoom) / 2;
	base->mouse.is_mouse_down = 0;
	base->color_change = -1;
	base->params.kz = 1.0f;
	min = base->min;
	base->sum_coord = 0;
	base->params.default_color = create_trgb(255, 255, 0, 0);
	while (min++ != base->max)
		base->sum_coord++;
}

int	render_win(t_base *base)
{
	mlx_destroy_image(base->mlx, base->img);
	render(base);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_base	*base;

	if (argc != 2)
		ft_putendl_fd("usage: ./fdf \"map_file.fdf\"", 1);
	if (argc != 2)
		exit(0);
	if (!valid_map(argv[1]))
		error_exit("Invalid map");
	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
		error_exit("Error malloc");
	base->color_detected = 0;
	parse(base, argv[1]);
	start_init(base);
	base->mlx = mlx_init();
	base->mlx_win = mlx_new_window(base->mlx, W, H, "FdF");
	render(base);
	mlx_hook(base->mlx_win, 4, (1L << 2), &mouse_down, base);
	mlx_hook(base->mlx_win, 5, (1L << 3), &mouse_up, base);
	mlx_hook(base->mlx_win, 6, (1L << 6), &mouse_move, base);
	mlx_key_hook(base->mlx_win, key_hook, base);
	mlx_hook(base->mlx_win, 17, 0, expose, base);
	mlx_loop_hook(base->mlx, render_win, base);
	mlx_loop(base->mlx);
}
