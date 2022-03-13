/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:13:51 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/12 23:38:12 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_coords(t_base *base, t_point *p1, t_point *p2)
{
	p1->y *= (float) base->params.zoom;
	p1->x *= (float) base->params.zoom;
	p2->y *= (float) base->params.zoom;
	p2->x *= (float) base->params.zoom;
}

void	trans_coords(t_base *base, t_point *p1, t_point *p2)
{
	p1->y += (float) base->params.tran_y;
	p1->x += (float) base->params.tran_x;
	p2->y += (float) base->params.tran_y;
	p2->x += (float) base->params.tran_x;
}

void	trans_coords_con(t_point *p1, t_point *p2, int x, int y)
{
	p1->y += (float) y;
	p1->x += (float) x;
	p2->y += (float) y;
	p2->x += (float) x;
}

void	rotate(t_point *p, t_base *r)
{
	t_point		v;
	double		x;
	double		y;
	double		z;

	x = p->x;
	z = p->z ;
	v.x = (float)(cos(r->params.angle_y) * x + sin(r->params.angle_y) * z);
	v.z = (float)(-sin(r->params.angle_y) * x + cos(r->params.angle_y) * z);
	y = p->y;
	z = v.z;
	v.y = (float)(cos(r->params.angle_x) * y - \
				sin(r->params.angle_x) * z);
	v.z = (float)(sin(r->params.angle_x) * y + cos(r->params.angle_x) * z);
	v.color = p->color;
	*p = v;
}

void	rotate2(t_point *p, t_base *base)
{
	p->x = p->x + cos(base->params.angle_y) * p->z;
	p->y = p->y + sin(base->params.angle_x) * p->z;
}
