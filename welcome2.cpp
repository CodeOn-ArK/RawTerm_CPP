//TODO : curs_border(3X) may be used later
#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <string>

//#include "Final_Project.cpp"
using namespace std;

void displayer();
void input_display();
void trans_rec_win();
void clear_lines();
int truncater(string&, int);
void menu_call();

WINDOW* win;

/********************-CLASS-**********************/

class conversion {
 private:
 protected:
 public:
  char* str;
  char *partition[20], *head[20];
  int len, div_len;

  conversion();
  conversion(string& s);
  void call_partition();
  void display(int start_col);
};

/******************-FUNCTIONS-*********************/
conversion::conversion() {
  str = new char;
  len = 0;
}

conversion::conversion(string& s) {
  len = s.size();
  div_len = len / 90;
  str = new char[len];
  for (int i = 0; i < 20; i++) {
    partition[i] = new char[90];
    head[i] = partition[i];
  }

  for (int i = 0; i < len; i++) {
    str[i] = s[i];
  }
  call_partition();
}

void conversion::call_partition() {
  for (int i = 0; i < div_len + 1; i++) {
    partition[i] = head[i];
    for (int j = 0; j < 90; j++) {
      *(partition[i]++) = str[90 * i + j];
    }
  }
}

void conversion::display(int start_col) {
  for (int i = 0; i <= div_len; i++) {
    partition[i] = head[i];
    mvprintw(start_col + i, 2, partition[i]);
  }
}

void trans_rec_win() {
  displayer();
  input_display();
}

void displayer(void) {
  initscr();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  win = newwin(46, 200, 1, 1);
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  mvwvline(win, 1, 95, '|', 44);
  wattron(win, COLOR_PAIR(1));
  wattron(win, A_BOLD);
  wattron(win, A_STANDOUT);
  mvwprintw(win, 0, 45, "TX");
  mvwprintw(win, 0, 140, "RX");
  wattroff(win, A_STANDOUT);
  wattroff(win, COLOR_PAIR(1));
  mvprintw(47, 5, "Enter here -->");
  wattroff(win, A_BOLD);
  mvwhline(win, 45, 1, '-', 180);

  refresh();
  wrefresh(win);
  move(47, 20);
}

void input_display() {
  string line;
  int i = 2, col = 0;
  int ch;
  while (ch = wgetch(stdscr)) {
    if (ch == '\n') {
      if (line.size() < 90) {
        mvwprintw(win, i, 0, line.c_str());// line.substr(2,6));
        wrefresh(win);
        refresh();
      } else
        i = truncater(line, i);
      i++;
      clear_lines();
      line.clear();
      col = 0;
      move(47, 20);
    } else if (ch == KEY_BACKSPACE) {
      if (!col) continue;
      line.pop_back();
      clear_lines();
      mvprintw(47, 20, line.c_str());
      move(47, 20 + --col);
    } else if (ch == KEY_F(1)) {
        int x, y;
        getyx(stdscr, y, x);
        menu_call();
        refresh();
        redrawwin(win);
        wrefresh(win);
        move(y, x);
    } else {
      line.push_back(ch);
      mvprintw(47, 20, line.c_str());
      move(47, 20 + ++col);
    }
  }

  endwin();
}

void clear_lines(void) {
  move(47, 20);
  clrtoeol();
  move(48, 0);
  clrtoeol();
  move(49, 0);
  clrtoeol();
}

int truncater(string& line, int start_row) {
  int inc;

  conversion classy(line);

  classy.display(start_row);
  inc = (line.size() / 90) + 1;
  start_row += inc;

  return start_row;
}
