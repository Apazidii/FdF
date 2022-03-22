/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:20:13 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/08 20:20:13 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

long	ft_mod(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

int	ft_inwin_x(float a)
{
	if (a < 0)
		return (0);
	if (a >= W)
		return (W - 1);
	return ((int) a);
}

int	ft_inwin_y(float a)
{
	if (a < 0)
		return (0);
	if (a >= H)
		return (H - 1);
	return ((int) a);
}

void	max_in_matrix(t_base *base)
{
	int	i;
	int	j;

	base->max = base->matrix[0][0]->z;
	base->min = base->max;
	i = 0;
	while (i < base->size_y)
	{
		j = 0;
		while (j < base->size_x)
		{
			if (base->max < base->matrix[i][j]->z)
				base->max = base->matrix[i][j]->z;
			if (base->min > base->matrix[i][j]->z)
				base->min = base->matrix[i][j]->z;
			j++;
		}
		i++;
	}
}

int is_duplicate(int k)
{
	static int f;
	static int l;

	if (!f)
	{
		l = k;
		f = 1;
	}
	if (k == l)
		return (1);
	return (0);
}

