#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

typedef struct design {
        int check;
} design;

design d[10][10];

int result = 0;
int x=11, y=6;
int test = 1;

int start(char *filename[]);
