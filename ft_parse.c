/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:10:00 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/10 03:13:52 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*create_coord(char *s, t_base *base)
{
	t_coord	*res;
	int		color;
	int		f;

	res = (t_coord *)malloc(sizeof(t_coord));
	res->z = ft_atoi(s);
	color = atoi_hex(s, &f);
	base->color_detected = (base->color_detected || !f);
	res->color = color;
	res->color_defined = !f;
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
	res = (t_coord **)malloc(sizeof(t_coord *) * base->size_x);
	if (!res)
		return (NULL);
	i = 0;
	while (i < base->size_x)
	{
		res[i] = create_coord(arr[i], base);
		i++;
	}
	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
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
		error_exit("Error malloc");
	i = 0;
	while (i < base->size_y)
	{
		mat[i] = parse_line(fd, base);
		if (mat[i] == NULL)
			free_base(base);
		if (mat[i] == NULL)
			error_exit("Error malloc");
		i++;
	}
	close(fd);
	base->matrix = mat;
	max_in_matrix(base);
}
