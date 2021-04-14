/*TODO : curs_border(3X) may be used later*/
#ifndef WELCOME2_CPP
#define WELCOME2_CPP

#include "RawTerm.hpp"
extern time_printing timeObj;
extern log_class logObj;
extern int flag;
extern class_mem memory;

const int TEXT_WIDTH = 78;

WINDOW* win;
vector<string> lines_buffer;

/********************-CLASS-**********************/

class conversion {
 private:
 protected:
 public:
  char* str;
  char *partition[20], *head[20];
  int len, div_len;

  conversion();
  conversion(const string& s);
  void call_partition();
  void display(int start_col);
};

/******************-FUNCTIONS-*********************/
conversion::conversion() {
  str = new char;
  len = 0;
}

conversion::conversion(const string& s) {
  len = s.size();
  div_len = len / TEXT_WIDTH;
  str = new char[len + 1];
  for (int i = 0; i < 20; i++) {
    partition[i] = new char[TEXT_WIDTH];
    head[i] = partition[i];
  }

  for (int i = 0; i < len; i++) {
    str[i] = s[i];
  }
  str[len] = '\0';  // C strings must end with a '\0'
  call_partition();
}

void conversion::call_partition() {
  for (int i = 0; i < div_len + 1; i++) {
    partition[i] = head[i];
    for (int j = 0; j < TEXT_WIDTH; j++) {
      //  if (timeObj.get_enable_status() && j == 0)
      //  *(partition[i]++) = str[(TEXT_WIDTH - 15) * i + j];
      // else
      *(partition[i]++) = str[TEXT_WIDTH * i + j];
    }
  }
}

void conversion::display(int start_col) {
  string final_line = "";

  if (timeObj.get_enable_status()) {
    final_line += print_time() + string(4, ' ');
  } else {
    final_line += string(16, ' ');
  }

  for (int i = 0; i <= div_len; i++) {
    partition[i] = head[i];
    final_line += partition[i];
    lines_buffer.push_back(final_line);

    if (logObj.get_log_status()) {
      logObj.generate_log(final_line.c_str());
    }

    mvwprintw(win, start_col + i, 0, final_line.c_str());
    final_line = string(16, ' ');
  }

  refresh();
  wrefresh(win);
}

void init_displayer() {
  initscr();
  start_color();
  cbreak();
  noecho();
  win = newwin(51, 200, 1, 1);
  keypad(win, TRUE);
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
}

void trans_rec_win() {
  init_displayer();
  displayer();
  input_display();
}

void displayer() {
  mvwvline(win, 1, 95, '|', 44);
  wattron(win, COLOR_PAIR(1));
  wattron(win, A_BOLD);
  wattron(win, A_STANDOUT);
  mvwprintw(win, 0, 45, "TX");
  mvwprintw(win, 0, 140, "RX");
  wattroff(win, A_STANDOUT);
  wattroff(win, COLOR_PAIR(1));
  mvwhline(win, 45, 1, '-', 180);
  wmove(win, 46, 0);
  wclrtoeol(win);
  clear_lines();
  curs_set(1);
  mvwprintw(win, 46, 5, "Enter here -->");
  wattroff(win, A_BOLD);
  if (flag) {
    lines_buffer.clear();
  }

  for (size_t i = 0; i < lines_buffer.size(); i++) {
    // (i + 1) to account for the RX and TX headers
    mvwprintw(win, i + 1, 0, lines_buffer[i].c_str());
  }

  refresh();
  wrefresh(win);
  wmove(win, 46, 20);
}

void displayer(int y, int x, const string& lin) {
  displayer();
  mvwprintw(win, 46, 20, lin.c_str());
  refresh();
  wrefresh(win);
  wmove(win, y, x);
}

void input_display() {
  string line, time;
  int i = 1, col = 0;
  int ch;
  lines_buffer.clear();
  while (ch = wgetch(win)) {
    if (ch == '\n') {
      memory.devObj.write(line.c_str());
      if (flag) i = 1;
      if (line.size() < TEXT_WIDTH) {
        string final_line;

        if (timeObj.get_enable_status()) {
          final_line = print_time() + string(4, ' ') + line;
        } else {
          final_line = string(16, ' ') + line;
        }

        if (logObj.get_log_status()) {
          logObj.generate_log(final_line.c_str());
        }

        lines_buffer.push_back(final_line);
        mvwprintw(win, i, 0, final_line.c_str());  // line.substr(2,6));

        refresh();
        wrefresh(win);
        flag = 0;

      } else {
        i = truncater(line, i);
      }

      i++;
      clear_lines();
      line.clear();
      col = 0;
      wmove(win, 46, 20);

    } else if (ch == KEY_BACKSPACE) {
      if (!col) continue;
      line.pop_back();
      clear_lines();
      mvwprintw(win, 46, 20, line.c_str());
      wmove(win, 46, 20 + --col);
    } else if (ch == KEY_F(1)) {
      int x, y;
      getyx(win, y, x);
      wclear(win);
      wrefresh(win);
      menu_call();
      displayer(y, x, line);
      refresh();
      wrefresh(win);
    } else {
      line.push_back(ch);
      mvwprintw(win, 46, 20, line.c_str());
      wmove(win, 46, 20 + ++col);
    }
  }

  endwin();
}

void clear_lines(void) {
  wmove(win, 46, 20);
  wclrtoeol(win);
  wmove(win, 47, 0);
  wclrtoeol(win);
  wmove(win, 48, 0);
  wclrtoeol(win);
  wmove(win, 49, 0);
  wclrtoeol(win);
  wmove(win, 50, 0);
  wclrtoeol(win);
}

int truncater(const string& line, int start_row) {
  int inc;

  conversion classy(line);

  classy.display(start_row);
  inc = (line.size() / TEXT_WIDTH) + 1;
  start_row += inc;
  lines_buffer.push_back(string());

  return start_row;
}

#endif
