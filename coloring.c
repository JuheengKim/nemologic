#include "coloring.h"

design d[10][20];

int result = 0;
int x=11, y=6;
int test = 1;
FILE *fp_ = NULL;

int start(char *filename) {

    WINDOW * mainwin, * childwin;

    int key;
    int count, value, i, j;
    int q = 10, p = 10;
    int row_x = 8, row_y = 6;
    int col_x = 11, col_y = 4;

    FILE *fp = fopen(filename, "r");

    mainwin = initscr();

    start_color(); 
    init_pair(test, COLOR_WHITE, COLOR_BLACK);
    noecho();
    keypad(mainwin, TRUE);

    // create childwin and sketch design 
    childwin = subwin(mainwin, 12, 21, 5, 10);
    box(childwin, 0, 0);

    //row 
    while (!feof(fp)) {
            fscanf(fp, "%d", &count);

         for (i=0; i<count; i++) {
                fscanf(fp, "%d", &value);
	        move(row_y, row_x);
                attron(COLOR_PAIR(test));
                addch(value + '0');
                attroff(COLOR_PAIR(test));
                refresh();
	        row_x--; row_x--;
         }
	 row_y++; row_x = 8; q--;
	 if (q == 0) break;
   }

    //col
    while (!feof(fp)) {
            fscanf(fp, "%d", &count);

            for (i=0; i<count; i++) {
                    fscanf(fp, "%d", &value);
                    move(col_y, col_x);
                    attron(COLOR_PAIR(test));
                    addch(value + '0');
                    attroff(COLOR_PAIR(test));
                    refresh();
                    col_y--; 
            }
	    
	    p--;
            if (p == 0) break;

	    col_x++; col_y = 15;
	    for (i=0; i<15; i++) {
	    	if (i != 10) {
		move(col_y, col_x);
                attron(COLOR_PAIR(test));
                addch('|');
                attroff(COLOR_PAIR(test));
                refresh();
		}
                col_y--;

	    }
            col_x++; col_y = 4;
      	}
     	test++;
	fclose(fp);

	insertAnswer(filename);
 
	//define initial position
	move(y, x);    
    	refresh();

	//keyboard
	while (result !=1) {
		
		key = getch();
		
		if (key == KEY_UP){
			y -= 1;	
			if ( y > 5 ) 
				move(y,x);		
			else 
				y += 1;
		} else if (key == KEY_DOWN) {
			y += 1;
			if ( y < 16 ) 
                		move(y, x);
            		else
				y -= 1;	
		} else if (key == KEY_RIGHT) {
			x += 2;
			if ( x < 30 )
				move(y, x);	
			else 
				x -= 2;
		} else if (key == KEY_LEFT) {
			x -= 2;
			if ( x > 10 )
				move(y, x);
			else
				x += 2;
		} else if (key == ' ') {
			if (!d[y-6][x-11].check || d[y-6][x-11].check == 0) { 
				d[y-6][x-11].check = 1;
				init_pair(test, COLOR_BLACK, COLOR_WHITE);
			}else {
				d[y-6][x-11].check = 0;
				init_pair(test, COLOR_WHITE, COLOR_BLACK);
			}
			attron(COLOR_PAIR(test));
                        move(y, x);
                        addstr(" ");

                        attroff(COLOR_PAIR(test));
                        refresh();
                        move(y, x);
                        refresh();
                        test++;
		} else if (key == 'r'){
			for(i=0;i<10;i++){
				for(j=0;j<20;j=j+2){
					if(d[i][j].check == 1||d[i][j].check == -1){
						d[i][j].check = 0;
						init_pair(test, COLOR_WHITE, COLOR_BLACK);
						attron(COLOR_PAIR(test));
						move(i+6, j+11);
						addstr(" ");
	
						attroff(COLOR_PAIR(test));
						refresh();
						test++;
					}

				}
			}
			x=11;
			y=6;
			move(y, x);
			refresh();
			
		}
		else if (key == 'd'){
			for(i=0;i<10;i++){
				for(j=0;j<20;j=j+2){
					if(d[i][j].check == -1){
						d[i][j].check = 0;
						init_pair(test, COLOR_WHITE, COLOR_BLACK);
						attron(COLOR_PAIR(test));
						move(i+6, j+11);
						addstr(" ");

						attroff(COLOR_PAIR(test));
						refresh();
						test++;
					}
				}
			}
			move(y, x);
			refresh();
		}else if (key == 'f'){
			d[y-6][x-11].check = -1;
			init_pair(test, COLOR_MAGENTA, COLOR_RED);
      			attron(COLOR_PAIR(test));
         		move(y, x);
         		addstr(" ");
         
        		attroff(COLOR_PAIR(test));
        		refresh();
         		move(y, x);
         		refresh();
         		test++;
      		}         		
		else if (key=='q') {
			result = 1;
		}
	}

    delwin(childwin);
    delwin(mainwin);
    endwin();
    refresh();
 
    return EXIT_SUCCESS;
}

void insertAnswer(char *filename) {
	int i, j, value;	
	char answerFile[10] = "a_";
	strcat(answerFile, filename);
         
	fp_ = fopen(answerFile, "r");

	for(i=0; i<10; i++) {
		for (j=0; j<19; j+=2){
			fscanf(fp_, "%d", &value);
			d[i][j].answer = value;
			d[i][j].check = 0;
		}
	}
	fclose(fp_);
}

int checkAnswer() {
	int i, j, result = 1;
      	for(i=0; i<10; i++) {
                for (j=0; j<19; j+=2){
             		if (d[i][j].answer != d[i][j].check){
				result = 0;
				break;
			}
                }
        }
	return result;
}
