#include<stdio.h>
#include<curses.h>


int main()
{
	initscr();
	clear();
	move( 10, 20 );
	addstr("Hello,world");	
	move(LINES-1, 0 );
	printf("LINES=%d\n",LINES);
	refresh();
	getch();
	endwin();

	return 0;
}

