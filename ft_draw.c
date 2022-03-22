/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:10:23 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/14 12:31:18 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_base *base, int x, int y, int color)
{
	char	*dst;

	dst = base->addr + (y * base->line_length + x * (base->bits_per_pixel / 8));
	if (dst - base->addr > 0)
		*(unsigned int *)dst = color;
}

void	apply_params(t_base *base, t_point *p1, t_point *p2)
{
	trans_coords_con(p1, p2, -(base->size_x / 2), -(base->size_y / 2));
	rotate(p1, base);
	rotate(p2, base);
	trans_coords_con(p1, p2, (base->size_x / 2), (base->size_y / 2));
	zoom_coords(base, p1, p2);
	trans_coords(base, p1, p2);
}

void	draw_line(t_base *base, t_point *p1, t_point *p2)
{
	float	x_step;
	float	y_step;
	float	c_step;
	float	max;
	float	color;

	color = 0;
	apply_params(base, p1, p2);
	max = ft_max((float)ft_mod((int)(p2->x - p1->x)), \
				(float)ft_mod((int)(p2->y - p1->y)));
	x_step = (p2->x - p1->x) / max;
	y_step = (p2->y - p1->y) / max;
	c_step = 1.0f / max;
	while ((int)(p2->x - p1->x) || (int)(p2->y - p1->y))
	{
		my_mlx_pixel_put(base, ft_inwin_x(p1->x), ft_inwin_y(p1->y), \
		create_color(p1->color, p2->color, color));
		p1->x += x_step;
		p1->y += y_step;
		color += c_step;
	}
	free(p1);
	free(p2);
}

void	draw(t_base *base)
{
	int	i;
	int	j;

	i = 0;
	while (i < base->size_y)
	{
		j = 0;
		while (j < base->size_x)
		{
			if (i != base->size_y - 1)
				draw_line(base, create_point(base, j, i), \
				create_point(base, j, i + 1));
			if (j != base->size_x - 1)
				draw_line(base, create_point(base, j, i), \
				create_point(base, j + 1, i));
			j++;
		}
		i++;
	}
}
