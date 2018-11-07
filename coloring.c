#include <stdio.h>
#include <curses.h>

int result = 0;
int x=5, y=5;

void  main() {

	int key;
	
	initscr();
	clear();
	move(5, 5);
	keypad(stdscr, TRUE);
	refresh();

	while (result !=1) {
		
		key = getch();
		
		if (key == KEY_UP){
			x -= 1;	
			if (x > 0 && y >0) 
				move(x,y);		
			else 
				x += 1;
		} else if (key == KEY_DOWN) {
			x += 1;
			if (x > 0 && y >0) 
                move(x,y);
            else
				x -= 1;	
		} else if (key == KEY_RIGHT) {
			y += 1;
			if (x>0 && y>0)
				move(x,y);	
			else 
				y -= 1;
		} else if (key == KEY_LEFT) {
			y -= 1;
			if (x>0 && y>0)
				move(x, y);
			else
				y += 1;
		} else {
			result = 1;
		}
		refresh();
	}
	endwin();
}
