/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:49 by dgalactu          #+#    #+#             */
/*   Updated: 2021/12/02 15:40:09 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	move_buff(t_buff *buff, t_list *list, int *res)
{
	while ((buff->ret > 0) && (buff->arr[buff->idc] != '\n'))
	{
		list->arr[list->len] = buff->arr[buff->idc];
		buff->idc++;
		list->len++;
		buff->ret--;
		*res = *res + 1;
	}	
}

static int	copy_buff(t_buff *buff, t_list *list, int *res)
{
	int	is_line_end;

	is_line_end = 0;
	move_buff(buff, list, res);
	if ((buff->ret > 0) && (buff->arr[buff->idc] == '\n'))
	{
		is_line_end = 1;
		list->arr[list->len] = buff->arr[buff->idc];
		buff->idc++;
		list->len++;
		*res = *res + 1;
		buff->ret--;
	}
	if (buff->ret == 0)
		buff->idc = 0;
	return (is_line_end);
}

static t_list	*read_list(t_buff *buff, t_list *list, int *res, int fd)
{
	if (copy_buff(buff, list, res))
		return (list);
	buff->ret = read(fd, buff->arr, BUFFER_SIZE);
	while (buff->ret > 0)
	{
		list = list_next(list);
		if (!list)
			return (NULL);
		if (copy_buff(buff, list, res))
			return (list);
		buff->ret = read(fd, buff->arr, BUFFER_SIZE);
	}
	if (buff->ret == -1)
	{
		buff->ret = 0;
		return (NULL);
	}
	return (list);
}

static char	*gen_res(t_list *list, char **res, int res_size)
{
	unsigned int	i;
	unsigned int	j;

	if (res_size == 0)
		return (NULL);
	*res = (char *)malloc(sizeof(char) * (res_size + 1));
	if (!*res)
		return (NULL);
	i = 0;
	while (list)
	{
		j = 0;
		while (j < list->len)
		{
			(*res)[i] = list->arr[j];
			i++;
			j++;
		}
		list = list->next;
	}
	(*res)[res_size] = '\0';
	return (*res);
}

char	*get_next_line(int fd)
{
	static t_buff	buffs[OPEN_MAX];
	t_list			*list;
	char			*res;
	int				res_size;

	res_size = 0;
	res = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	list = new_list();
	if (!list)
		return (NULL);
	if (!read_list(&buffs[fd], list, &res_size, fd))
	{
		free_list(&list);
		return (NULL);
	}
	gen_res(list, &res, res_size);
	free_list(&list);
	return (res);
}
