#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
	int nb_line;
	char empty;
	char obst;
	char full;
	char **map;
} t_map;

#endif