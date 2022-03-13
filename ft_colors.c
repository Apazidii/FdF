/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:06:29 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/10 03:26:36 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_from_z(float z, t_base *base)
{
	int	pos;
	int	all;

	all = base->sum_coord;
	pos = (int) z - (base->min);
//	return (create_trgb(255, (int)(255 - (255 * ((float) pos / (float) all))), \
//	(int)(255 - (255 * ((float) pos / (float) all))), 255));
	return (create_trgb(255,(int)(255 - (255 * ((float) pos / (float) all))), 255,\
	(int)(255 - (255 * ((float) pos / (float) all)))));

}

int	color_from_coords(t_base *base, int x, int y)
{
	if (base->color_detected == 0)
		return (color_from_z((float) base->matrix[y][x]->z, base));
	if (base->matrix[y][x]->color_defined)
		return (create_trgb(255, (base->matrix[y][x]->color >> 16) & 0xFF, \
									(base->matrix[y][x]->color >> 8) & 0xFF, \
									base->matrix[y][x]->color & 0xFF));
	else
		return (create_trgb(255, 255, 255, 255));
}

int	create_color(int c1, int c2, float prc)
{
	int	r;
	int	g;
	int	b;

	r = (int)(((float)(get_r(c2) - get_r(c1)) *prc) + (float) get_r(c1));
	g = (int)(((float)(get_g(c2) - get_g(c1)) *prc) + (float) get_g(c1));
	b = (int)(((float)(get_b(c2) - get_b(c1)) *prc) + (float) get_b(c1));
	return (create_trgb(255, r, g, b));
}
