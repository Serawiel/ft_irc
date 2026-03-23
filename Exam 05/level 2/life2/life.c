#include "life.h"

int is_valid(char *str)
{
	for (int i=0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

void free_board(t_life life, char **board)
{
	for (int i = 0; i < life.height; i++)
		free(board[i]);
	free(board);
}

void ftputstr(char *str)
{
	for (int i = 0; str[i]; i++)
		putchar(str[i]);
}

int init_life(t_life *life, char **av)
{
	if (!is_valid(av[1]))
		return(-1);
	life->width = atoi(av[1]);
	if (!is_valid(av[2]))
		return(-1);
	life->height = atoi(av[2]);
	if (!is_valid(av[3]))
		return (-1);
	life->iter = atoi(av[3]);
	life->board = calloc(life->height, sizeof(char *));
	if (!life->board)
		return (-1);
	for (int line = 0; line < life->height; line++)
	{
		life->board[line] = calloc(life->width + 1, sizeof(char));
		if (!life->board[line])
		{
			free_board(*life, life->board);
			return (-1);
		}
		for (int col = 0; col < life->width; col++)
			life->board[line][col] = ' ';
	}
	return(0);
}

int count(t_life life, int col, int line)
{
	int count = 0;
	for(int i = line - 1; i <= line + 1; i++)
	{
		for (int j = col - 1; j <= col + 1; j++)
		{
			if (j == col && i == line)
				continue;
			if (i >= 0 && (i < life.height) && (j >= 0) && (j < life.width))
			{
				if (life.board[i][j] == 'O')
					count++;
			}
		}
	}
	return (count);
}

void game(t_life *life)
{
	char **new_board;

	new_board = calloc(life->height, sizeof(char *));
	if (!new_board)
		return;
	for (int line = 0; line < life->height; line++)
	{
		new_board[line] = calloc(life->width + 1, sizeof(char));
		if (!new_board[line])
		{
			free_board(*life, new_board);
			return;
		}
		for (int col = 0; col < life->width; col ++)
		{
			int neighbors = count(*life, col, line);
			if (life->board[line][col] == 'O')
			{
				if (neighbors == 2 || neighbors == 3)
					new_board[line][col] = 'O';
				else
					new_board[line][col] = ' ';
			}
			else
			{
				if (neighbors == 3)
					new_board[line][col] = 'O';
				else
					new_board[line][col] = ' ';
			}
		}
	}
	for (int i = 0; i < life->height; i++)
	{
		for (int j = 0; j < life->width; j++)
			life->board[i][j] = new_board[i][j];
	}
	free_board(*life, new_board);
}

int main(int ac, char **av)
{
	t_life life;
	int is_writing = 0;
	char c;
	int col = 0;
	int line = 0;

	if (ac != 4)
		return (-1);
	if (init_life(&life, av) == -1)
		return (-1);
	while (read(0, &c, 1) > 0)
	{
		if(c == 'w' && (line > 0))
			line--;
		if(c == 's' && (line < (life.height - 1)))
			line++;
		if(c == 'a' && (col > 0))
			col--;
		if(c == 'd' && (col < (life.width- 1)))
			col++;
		if (c == 'x')
			is_writing = !is_writing;
		if (is_writing == 1)
			life.board[line][col] = 'O';
	}
	for (int i = 0; i < life.iter; i++)
		game(&life);
	for (int i = 0; i < life.height; i++)
	{
		ftputstr(life.board[i]);
		putchar('\n');
	}
	free_board(life, life.board);
	return(0);
}