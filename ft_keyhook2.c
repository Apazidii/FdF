/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:47:26 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/14 14:48:44 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}

void	zoom(int key, t_base *base)
{
	if (key == 4)
		base->params.zoom += 1;
	if (key == 5 && base->params.zoom > 1)
		base->params.zoom -= 1;
	base->params.tran_x = (W / 2) - (base->size_x * base->params.zoom) / 2;
	base->params.tran_y = (H / 2) - (base->size_y * base->params.zoom) / 2;
}

void	koef_z(int key, t_base *base)
{
	if (key == 101)
		base->params.kz -= 0.1f;
	if (key == 113)
		base->params.kz += 0.1f;
}

void	project(int key, t_base *base)
{
	if (key == 49)
	{
		base->params.angle_x = 0.0f;
		base->params.angle_y = 0.0f;
	}
	if (key == 50)
	{
		base->params.angle_x = 0.0f;
		base->params.angle_y = M_PI_2;
	}
	if (key == 51)
	{
		base->params.angle_x = M_PI_2;
		base->params.angle_y = M_PI_2;
	}
}
