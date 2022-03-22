/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:24:05 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/08 20:48:01 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_down(int button, int x, int y, t_base *base)
{
	if (button == 4 || button == 5)
		zoom(button, base);
	base->mouse.is_mouse_down = 1;
	base->mouse.x = x;
	base->mouse.y = y;
	return (0);
}

int	mouse_up(int button, int x, int y, t_base *base)
{
	(void) button;
	(void) x;
	(void) y;
	base->mouse.is_mouse_down = 0;
	return (0);
}

int	mouse_move(int x, int y, t_base *base)
{
	if (!base->mouse.is_mouse_down)
		return (0);
	if (base->mouse.y < y)
		base->params.angle_x += (base->mouse.y - y) * 0.005;
	if (base->mouse.y > y)
		base->params.angle_x += (base->mouse.y - y) * 0.005;
	if (base->mouse.x < x)
		base->params.angle_y += (base->mouse.x - x) * 0.005;
	if (base->mouse.x > x)
		base->params.angle_y += (base->mouse.x - x) * 0.005;
	base->mouse.x = x;
	base->mouse.y = y;
	return (0);
}
