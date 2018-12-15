#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <string.h>

typedef struct design {
        int check;
	int answer;
} design;
design d[10][20];

int result = 0;
int x=11, y=6;
int test = 1;
FILE *fp_ = NULL;

int start(char *filename);
void insertAnswer(char *filename);
int checkAnswer();
