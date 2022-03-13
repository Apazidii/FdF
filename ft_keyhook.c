/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:22:22 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/13 11:00:28 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	trans(int key, t_base *base)
{
	if (key == 65362)
		base->params.tran_y -= H / 100;
	if (key == 65364)
		base->params.tran_y += H / 100;
	if (key == 65361)
		base->params.tran_x -= W / 100;
	if (key == 65363)
		base->params.tran_x += W / 100;
	mlx_destroy_image(base->mlx, base->img);
	render(base);
}

void	zoom(int key, t_base *base)
{
	if (key == 4)
		base->params.zoom += 1;
	if (key == 5 && base->params.zoom > 1)
		base->params.zoom -= 1;
	base->params.tran_x = (W / 2) - (base->size_x * base->params.zoom) / 2;
	base->params.tran_y = (H / 2) - (base->size_y * base->params.zoom) / 2;
	mlx_destroy_image(base->mlx, base->img);
	render(base);
}

void	angle(int key, t_base *base)
{
	if (key == 97)
		base->params.angle_x -= 0.05;
	if (key == 100)
		base->params.angle_x += 0.05;
	if (key == 115)
		base->params.angle_y -= 0.05;
	if (key == 119)
		base->params.angle_y += 0.05;
	mlx_destroy_image(base->mlx, base->img);
	render(base);
}

void	ex(t_base *base)
{
	free_all(base);
	exit(0);
}

int	key_hook(int keycode, t_base *base)
{
	if (keycode == 65307)
		ex(base);
	if (keycode == 65362 || keycode == 65364 || \
		keycode == 65361 || keycode == 65363)
		trans(keycode, base);
	if (keycode == 61 || keycode == 45)
		zoom(keycode, base);
	if (keycode == 97 || keycode == 100 || keycode == 119 || keycode == 115)
		angle(keycode, base);
	return (0);
}

int expose(t_base *base)
{
	printf("qwe");
//	ex(base);
	return (0);
}
