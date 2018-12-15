#include <stdio.h>
#include <curses.h>
#include <string.h>
#include <menu.h>
#include <stdlib.h>          
#include "coloring.h"

int main(int argc, char **argv)
{

    int i, c;
    int key = 0;
    int resulting = 0;
    char *title  = "COLORING LOVE";
    int szer, dlug; 
    initscr();  
    keypad(stdscr, TRUE);

    start_color();

    getmaxyx(stdscr, szer, dlug); 
    move(szer/2, (dlug-strlen(title))/2); 
    printw(title); 
    refresh();
    
    WINDOW * menuwin=newwin(7, dlug-12, szer-9, 6); 
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, TRUE);

    char *menu[] = {
        "doan1",
        "doan2",
        "doan3",
        "doan4",
        "Exit",
    };
    int wybor;
    int zaznacz=0;

    while(1)
    {
        for(i = 0; i < 5; i++) {
            if(i == zaznacz)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, menu[i]);
            if (i == zaznacz)
                wattroff(menuwin, A_REVERSE);
        }

   //remove cursor
   curs_set(0);

        wybor = wgetch(menuwin);
        switch(wybor)
        {
        case KEY_UP:
            zaznacz--;
            if(zaznacz < 0) zaznacz = 0;
            break;
        case KEY_DOWN:
            zaznacz++;
            if(zaznacz > 4) zaznacz = 4;
            break;
        }

          if(wybor == 10) {
            if (zaznacz == 0) {
                     	curs_set(1);
         		delwin(menuwin);
                     	clear();
                	endwin();
                     	start("doan1");
            }
            if (zaznacz == 1) {
         		curs_set(1);
            		delwin(menuwin);
                	clear();
                     	endwin();
                     	start("doan2");
            }
            if (zaznacz == 2) {
         		curs_set(1);
                     	delwin(menuwin);
                     	clear();
                	endwin();
                     	start("doan3");
            }
            if (zaznacz == 3) {
         		curs_set(1);
                     	delwin(menuwin);
                     	clear();
         		endwin();
         		start("doan4");
            }
            if (zaznacz == 4) {
             break;
       	    }
         }
    }
   
    delwin(menuwin);
    endwin();
    return 0;
}
