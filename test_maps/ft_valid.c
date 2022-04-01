/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <dgalactu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:54:45 by dgalactu          #+#    #+#             */
/*   Updated: 2022/03/22 14:54:45 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*get_next_word(char const **s, char c)
{
	while (**s && **s == c)
		(*s)++;
	return ((char *)*s);
}

static char	*get_next_dl(char const **s, char c)
{
	while (**s && **s != c)
		(*s)++;
	return ((char *)*s);
}

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	nw;

	nw = 0;
	while (*s)
	{
		get_next_word(&s, c);
		if (*s)
			nw++;
		get_next_dl(&s, c);
	}
	return (nw);
}

int	valid_map(char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (errno != 0)
		exit_errno();
	line = get_next_line(fd);
	while (line)
	{
		if (!is_duplicate((int) count_words(line, ' ')))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}

int	is_duplicate(int k)
{
	static int	f;
	static int	l;

	if (!f)
	{
		l = k;
		f = 1;
	}
	if (k == l)
		return (1);
	return (0);
}
