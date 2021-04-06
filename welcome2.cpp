#include <ncurses.h>

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

void displayer();
void input_display();
void trans_rec_win();
void clear_lines();
int truncater(string&, int);

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
      if (line.size() < 20)
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

/********************-CLASS-**********************/

class conversion {
 private:
 protected:
 public:
  char* str;
  char* partition[20];
  int len, div_len, rem_len;
  conversion() {
    // str = new char*;
    //*str = new char;
    len = 0;
  }

  conversion(string& s) {
    len = s.size();
    div_len = len / 20;
    rem_len = len % 20;
    str = new char[len];
    partition[0] = new char[20];
    partition[1] = new char[20];
    partition[2] = new char[20];

    call_partition();
    for (int i = 0; i < 2; i++) {
      // str[i] = s[i];
      // DON'T USE -->      strcat(partition[i], s.substr(20 * i, 20 * (i +
      // 1)));
    }
    /*for (int i = 0; i < div_len; i++) {
      *str = s.substr(i, 20);
    }*/
  }

  void call_partition() {
    for (int i = 0; i < div_len; i++) {
      for (int j = 0; j < 20; j++) {
        //*(partition[i]) = str[i];
        strcat(*(partition[i]), str[i]);
        partition[i]++;
      }
    }
  }

  void display() { cout << "\n" << str << "\t" << len; }
};

/******************-FUNCTIONS-*********************/

/*********************-END-************************/

int truncater(string& line, int start_col) {
  int inc, col, size = line.size();

  conversion classy(line);
  inc = line.size() / 20;

  for (int col = 0; col < inc; col++) {
    // mvprintw(start_col + col, 0, classy.str[col]);  // line[20 * col + i]);
  }

  return inc;
}

int main() {
  trans_rec_win();

  return 0;
}
