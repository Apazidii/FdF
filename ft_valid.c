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

int valid_map(char *file_path)
{
	int fd;
	char *line;

	fd = open(file_path, O_RDONLY);
	if (errno != 0)
		exit_errno();
	line = get_next_line(fd);
	while (line)
	{
		if (!is_duplicate((int) count_words(line, ' ')))
			return (0);
		line = get_next_line(fd);
	}
	return (1);
}
