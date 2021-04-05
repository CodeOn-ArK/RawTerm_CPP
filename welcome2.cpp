#include <ncurses.h>

#include <iostream>
#include <string>
using namespace std;

void displayer();
void input_display();
void trans_rec_win();

void trans_rec_win() { displayer(); }

void displayer(void) {
  initscr();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  for (int i = 2; i <= 45; i++) mvprintw(i, 95, "|");
  attron(COLOR_PAIR(1));
  attron(A_BOLD);
  attron(A_STANDOUT);
  mvprintw(1, 45, "TX");
  mvprintw(1, 140, "RX");
  attroff(A_STANDOUT);
  attroff(COLOR_PAIR(1));
  mvprintw(47, 5, "Enter here -->");
  attroff(A_BOLD);

  refresh();
  for (int j = 2; j <= 180; j++) mvprintw(45, j, "_");
  move(47, 20);
  input_display();
}

void input_display() {
  string line;
  int i = 4, col = 0;
  int ch;
  while (ch = wgetch(stdscr)) {
    if (ch == '\n') {
      mvprintw(i, 2, line.c_str());
      move(47, 19);
      clrtoeol();
      i++;
      line.clear();
      col = 0;
      move(47, 20);
    } else if (ch == KEY_BACKSPACE) {
      if (!col) continue;
      line.pop_back();
      move(47, 20);
      clrtoeol();
      mvprintw(47, 20, line.c_str());
      move(47, 20 + --col);
    } else {
      line.push_back(ch);
      mvprintw(47, 20, line.c_str());
      move(47, 20 + ++col);
    }

    if (line == "quit") break;
  }

  getch();
  endwin();
}

int main() {
  trans_rec_win();

  return 0;
}
