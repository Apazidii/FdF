/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:22:22 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/22 11:59:02 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ex(t_base *base)
{
	free_all(base);
	exit(0);
}

void	change_color(t_base *base)
{
	char	*line;
	int		r;
	int		g;
	int		b;

	ft_putendl_fd("Enter r:", 1);
	line = get_next_line(0);
	r = ft_atoi(line);
	free(line);
	ft_putendl_fd("Enter g:", 1);
	line = get_next_line(0);
	g = ft_atoi(line);
	free(line);
	ft_putendl_fd("Enter b:", 1);
	line = get_next_line(0);
	b = ft_atoi(line);
	free(line);
	base->params.default_color = create_trgb(255, r, g, b);
	ft_putendl_fd("Color changed!", 1);
}

void	recolor(t_base *base)
{
	base->color_change *= -1;
}

int	key_hook(int keycode, t_base *base)
{
	if (keycode == 65513)
		recolor(base);
	if (keycode == 32)
		change_color(base);
	if (keycode == 49 || keycode == 50 || keycode == 51)
		project(keycode, base);
	if (keycode == 113 || keycode == 101)
		koef_z(keycode, base);
	if (keycode == 65307)
		ex(base);
	if (keycode == 65362 || keycode == 65364 || \
		keycode == 65361 || keycode == 65363)
		trans(keycode, base);
	if (keycode == 61 || keycode == 45)
		zoom(keycode, base);
	return (0);
}

int	expose(t_base *base)
{
	ex(base);
	return (0);
}
