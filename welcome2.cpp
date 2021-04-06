#include <ncurses.h>

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

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
/*********************-END-************************/

void displayer();
void input_display();
void trans_rec_win();
void clear_lines();
int truncater(string&, int);

int main() {
  trans_rec_win();

  return 0;
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
}

void input_display() {
  string line;
  int i = 4, col = 0;
  int ch;
  while (ch = wgetch(stdscr)) {
    if (ch == '\n') {
      if (line.size() < 90)
        mvprintw(i, 2, line.c_str());
      else
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

void clear_lines(void) {
  move(47, 20);
  clrtoeol();
  move(48, 0);
  clrtoeol();
  move(49, 0);
  clrtoeol();
}

int truncater(string& line, int start_col) {
  int inc;

  conversion classy(line);

  classy.display(start_col);
  inc = (line.size() / 90) + 1;
  start_col += inc;

  return start_col;
}
