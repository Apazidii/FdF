/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:10:00 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/22 13:47:23 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*create_coord(char *s, t_base *base)
{
	t_coord		*res;
	int			color;
	int			f;
	static int	k;

	res = (t_coord *)malloc(sizeof(t_coord));
	if (errno != 0)
	{
		free_matrix_i(base, k);
		free(base);
		exit_errno();
	}
	res->z = ft_atoi(s);
	color = atoi_hex(s, &f);
	base->color_detected = (base->color_detected || !f);
	res->color = color;
	res->color_defined = !f;
	k++;
	return (res);
}

t_coord	**parse_line(int fd, t_base *base)
{
	char	**arr;
	char	*line;
	t_coord	**res;
	int		i;

	line = get_next_line(fd);
	line = del_ln(line);
	arr = ft_split(line, ' ', &base->size_x);
	free(line);
	if (!arr)
		return (NULL);
	res = (t_coord **)malloc(sizeof(t_coord *) * base->size_x);
	if (!res)
		free_split(arr);
	if (!res)
		return (NULL);
	i = 0;
	while (i < base->size_x)
	{
		res[i] = create_coord(arr[i], base);
		i++;
	}
	free_split(arr);
	return (res);
}

void	count_lines(char	*file_path, t_base *base)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (errno != 0)
		exit_errno();
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	base->size_y = i;
}

void	parse(t_base *base, char *file_path)
{
	int		i;
	int		fd;
	t_coord	***mat;

	count_lines(file_path, base);
	fd = open(file_path, O_RDONLY);
	if (errno != 0)
		exit_errno();
	mat = (t_coord ***)malloc(sizeof(t_coord **) * base->size_y);
	if (!mat)
		free(base);
	if (!mat)
		exit_errno();
	i = -1;
	while (++i < base->size_y)
	{
		mat[i] = parse_line(fd, base);
		if (mat[i] == NULL)
			exit_errno();
	}
	close(fd);
	base->matrix = mat;
	max_in_matrix(base);
}
