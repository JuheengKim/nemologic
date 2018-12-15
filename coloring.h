#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <string.h>

typedef struct design {
        int check;
	int answer;
} design;

int start(char *filename);
void insertAnswer(char *filename);
int checkAnswer();
