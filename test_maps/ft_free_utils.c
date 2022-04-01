/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:18:11 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/22 13:38:05 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix_i(t_base *base, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < k / base->size_x)
	{
		j = 0;
		while (j < k % base->size_x)
		{
			free(base->matrix[i][j]);
			j++;
		}
		free(base->matrix[i]);
		i++;
	}
}

void	free_matrix(t_base *base)
{
	int	i;
	int	j;

	i = 0;
	while (i < base->size_y)
	{
		j = 0;
		while (j < base->size_x)
		{
			free(base->matrix[i][j]);
			j++;
		}
		free(base->matrix[i]);
		i++;
	}
	free(base->matrix);
}

void	free_all(t_base *base)
{
	free_matrix(base);
	mlx_destroy_image(base->mlx, base->img);
	mlx_destroy_window(base->mlx, base->mlx_win);
	mlx_destroy_display(base->mlx);
	free(base);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}
