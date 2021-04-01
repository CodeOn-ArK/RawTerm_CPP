#include <ncurses.h>
#include <iostream>
#include <string>
using namespace std;

void trans_rec_win(){

	initscr();
	start_color();
	echo();
	
	init_pair(1,COLOR_YELLOW,COLOR_BLACK);
	for(int i = 2;i <= 45;i++)
	  mvprintw(i,95,"|");
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	attron(A_STANDOUT);
	mvprintw(1,45,"TX");
	mvprintw(1,140,"RX");
	attroff(A_STANDOUT);
	attroff(COLOR_PAIR(1));
	mvprintw(47,5,"Enter here -->");
	attroff(A_BOLD);
	
	refresh();
	char ch ;
	string line;
	/*  while (1) {
	    ch = cin.gets();
	    cout.put(ch);

	    if (ch == '\r') break;
            
	  }*/
	int i = 4;
	while (ch = getch()) {
		if (ch == '\n'){
			mvprintw(i,85,line.c_str());
			move(47,19);
			clrtoeol();
			i++;
			line.clear();
		}
		else line.push_back(ch);
		if(line == "quit") break;
	}
	/*for(int i = 4;i <= 44;i++){
		cin >> ch;
	//	if(ch == "\r") break;
		mvprintw(i,105,ch.c_str());
		move(47,19);
		clrtoeol();
	}*/

	getch();
	endwin();
}

int main(){
	
	trans_rec_win();
	
	return 0;
}	
