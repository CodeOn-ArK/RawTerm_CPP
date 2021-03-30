#include <ncurses.h>

void wlkm(){
	initscr();
	start_color();
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_RED,COLOR_BLACK);
	attron(A_BOLD);
	attron(COLOR_PAIR(3));
	mvprintw(15,5,"#####################################################################################----WELCOME----#################################################################################");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(1));
	mvprintw(20,60,"%%%%%%%%%%%%%%%%------THIS PROGRAM EMULATES SERIAL TRMINAL IN C++------%%%%%%%%%%%%%%%%");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	mvprintw(27,10,"1.Colour Scheme -> It changes colour of menu.");
	mvprintw(29,10,"2.Device -> ");
	mvprintw(31,10,"3.Time Stamp -> ");
	mvprintw(33,10,"4.Generate Log -> ");
	mvprintw(35,10,"5.Clear Screen ->");
	mvprintw(37,10,"6.Baud Rate -> ");
	mvprintw(39,10,"7.Send Newline -> ");
	mvprintw(41,10,"8.EXIT Console -> ");
	mvprintw(43,10,"9.EXIT Menu -> ");
	attroff(COLOR_PAIR(2));
	attroff(A_BOLD);
	refresh();
	getch();
	endwin();
}

int main(){
	wlkm();
	return 0;
}
