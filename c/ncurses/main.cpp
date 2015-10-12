/*
Brooks Kindle
12/08/13

Simple test to figure out how to use ncurses
*/

#include <ncurses.h>

int main(void) {
        char exit = '\3'; //Ctrl-C
        char srslyExit = '\4'; //Ctrl-D
        initscr(); //initialize screen
        raw();
        noecho(); //prevent user typed characters from appearing on screen
        printw("Hello, world!\n"); 
        printw("Press Ctrl-C to exit!\n");
        char ch = '\0';

        do {
        ch = getch(); //wait for user input
        if(ch == exit) {
                printw("Okay, now press Ctrl-D to exit\n");
        }
        else {
                printw("You pressed: %c\n", ch);
        }
        refresh(); //refresh so our text displays on screen
        }while(ch != srslyExit);

        getch();
        endwin(); //close window
        return 0;
}//end main
