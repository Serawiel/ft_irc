#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_life
{
	int width;
	int height;
	int iter;
	char **board;
} t_life;

#endif