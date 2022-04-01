/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:18:34 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/14 13:23:43 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_base *base)
{
	base->img = mlx_new_image(base->mlx, W, H);
	base->addr = mlx_get_data_addr(base->img, &base->bits_per_pixel, \
							&base->line_length, &base->endian);
	draw(base);
	mlx_put_image_to_window(base->mlx, base->mlx_win, base->img, 0, 0);
}

char	*del_ln(char *s)
{
	int		n;
	char	*res;
	int		i;

	n = ft_strlen(s);
	if (s[n - 1] != '\n')
		return (s);
	res = (char *)malloc(sizeof(char) * n);
	i = 0;
	while (i < n - 1)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	free(s);
	return (res);
}

void	atoi_hex_utils(long int *res, char s)
{
	if (s >= '0' && s <= '9')
		*res = *res * 16 + (s - '0');
	if (s >= 'a' && s <= 'f')
		*res = *res * 16 + (10 + (s - 'a'));
	if (s >= 'A' && s <= 'F')
		*res = *res * 16 + (10 + (s - 'A'));
}

int	atoi_hex(char *s, int *f)
{
	long int	res;

	res = 0;
	*f = 0;
	while (*s != ',' && *s != '\0')
		s++;
	if (*s == ',')
		s++;
	if (*s == '0')
		s++;
	if (*s == 'x')
		s++;
	if (*s == '\0')
		*f = 1;
	while (*s != '\0' && ((*s >= '0' && *s <= '9') || \
	(*s >= 'a' && *s <= 'f') || (*s >= 'A' && *s <= 'F')))
	{
		atoi_hex_utils(&res, *s);
		s++;
	}
	return ((int) res);
}

t_point	*create_point(t_base *base, int x, int y)
{
	t_point	*res;

	res = (t_point *)malloc(sizeof(t_point) * 1);
	res->x = (float) x;
	res->y = (float) y;
	res->z = (float) base->matrix[y][x]->z;
	res->color = color_from_coords(base, x, y);
	return (res);
}
