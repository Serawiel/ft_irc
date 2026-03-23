#include "bsq2.h"

void	free_map(t_map map, int nline)
{
	for (int i = 0; i < nline; i++)
		free(map.map[i]);
	free(map.map);
}

void	print_map(t_map map)
{
	for (int i = 0; i < map.nb_line; i++)
		printf("%s\n", map.map[i]);
}

void	clean_exit(t_map map, char *line, FILE *stream, char *str, int nline)
{
	if (line)
		free(line);
	if (map.map)
		free_map(map, nline);
	printf("Error: %s\n", str);
	if (stream)
		fclose(stream);
}

void	skip_spaces(char *str, int *i)
{
	while (str[(*i)] == ' ')
		(*i)++;
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	first_line(t_map *map, char *line)
{
	int	i;

	i = 0;
	map->nb_line = 0;
	skip_spaces(line, &i);
	if (!is_digit(line[i]))
		return (-1);
	while (is_digit(line[i]))
		map->nb_line = map->nb_line * 10 + line[i++] - '0';
	skip_spaces(line, &i);
	if (map->nb_line <= 0)
		return (-1);
	if (!is_printable(line[i]))
		return (-1);
	map->empty = line[i++];
	skip_spaces(line, &i);
	if (!is_printable(line[i]) || (map->empty == line[i]))
		return (-1);
	map->obst = line[i++];
	skip_spaces(line, &i);
	if (!is_printable(line[i]) || (map->empty == line[i])
		|| (map->obst == line[i]))
		return (-1);
	map->full = line[i++];
	if (line[i] != '\n')
		return (-1);
	return (0);
}

int	validate_line(t_map map, char *line, int nread)
{
	for (int i = 0; i < nread - 1; i++)
	{
		if (line[i] != map.empty && line[i] != map.obst)
			return (-1);
	}
	return (0);
}

int	min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int	solve_bsq(t_map map)
{
	char	**calc;
	int		max;
	int		lmax;
	int		cmax;
	int		lsize;

	calc = NULL;
	max = 0;
	lmax = 0;
	cmax = 0;
	lsize = 0;
	calc = calloc(map.nb_line, sizeof(char *));
	if (!calc)
		return (-1);
	while (map.map[0][lsize])
		lsize++;
	for (int line = 0; line < map.nb_line; line++)
	{
		calc[line] = calloc(lsize + 1, sizeof(char));
		if (!calc[line])
			return (-1);
		for (int col = 0; col < lsize; col++)
		{
			if (map.map[line][col] == map.obst)
				calc[line][col] = 0;
			else if (line == 0 || col == 0)
				calc[line][col] = 1;
			else
				calc[line][col] = min(calc[line-1][col-1], calc[line-1][col], calc[line][col-1]) + 1;
			if (calc[line][col] > max)
			{
				max = calc[line][col];
				lmax = line;
				cmax = col;
			}
		}
	}
	for (int line = lmax - max + 1; line <= lmax; line++)
	{
		for (int col = cmax - max + 1; col <= cmax; col++)
			map.map[line][col] = map.full;
	}
	print_map(map);
	return (0);
}

int	main(int ac, char **av)
{
	FILE *stream;
	t_map map;
	map.map = NULL;
	char *line = NULL;
	ssize_t nread;
	size_t len = 0;
	int bnread = 0;
	int nbline = 0;

	if (ac != 1 && ac != 2)
		return (printf("Error: wrong args.\n"), -1);
	if (ac == 1)
		stream = stdin;
	else
		stream = fopen(av[1], "r");
	if (stream == NULL)
		return (clean_exit(map, line, stream, "open", 0), -1);
	if ((nread = getline(&line, &len, stream)) == -1)
		return (clean_exit(map, line, stream, "read", 0), -1);
	if (first_line(&map, line) == -1)
		return (clean_exit(map, line, stream, "invalid map", 0), -1);
	map.map = calloc(map.nb_line, sizeof(char *));
	if (!map.map)
		return (clean_exit(map, line, stream, "calloc map.map", 0), -1);
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		if (!line || (bnread && bnread != nread) || (line[nread - 1] != '\n')
			|| validate_line(map, line, nread) == -1)
			return (clean_exit(map, line, stream, "invalid map", nbline), -1);
		map.map[nbline] = calloc(nread, sizeof(char));
		if (!map.map[nbline])
			return (clean_exit(map, line, stream, "calloc map.map", 0), -1);
		for (int i = 0; i < nread - 1; i++)
			map.map[nbline][i] = line[i];
		nbline++;
		if (nbline > map.nb_line)
			return (clean_exit(map, line, stream, "invalid map", nbline), -1);
		bnread = nread;
	}
	if (nbline != map.nb_line)
		return (clean_exit(map, line, stream, "invalid map", nbline), -1);
	if (solve_bsq(map) == -1)
		return (clean_exit(map, line, stream, "solving", nbline), -1);
	if (line)
		free(line);
	if (map.map)
		free_map(map, nbline);
	fclose(stream);
	return (0);
}