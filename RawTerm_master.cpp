/*
# RawTerm
This is a Serial Terminal Emulator and is currently not portable to any other
Operating System other than Linux. This C++ project was written as a final group
project at the end of our Fouth Semester(2nd Year).

## Features Covered
The main C++ / OOP features that were aimed to be covered in this project are
listed below:
- [x] Encapsulation in the form of Classes
- [x] Inheritance
- [x] File handling
- [x] STL
- [ ] Exception Handling
- [ ] Templates

## Collaboration
This project was made in collaboration with [ @CodeOn-ArK
](https://github.com/CodeOn-ArK),

[ @aritra1911 (Aritra Sarkar) ](https://github.com/aritra1911),

[ @Programish (Pushpendra Kumar) ](https://github.com/Programish) and

[ @Saptarshi434 (Saptarshi Mondal) ](https://github.com/Saptarshi434).
TODO WARNING: THIS project will not compile in the following fashion,
                To execute this project fork our repo from
                RawTerm_CPP@CodeOn-ArK
*/
#ifndef RAWTERM_HPP
#define RAWTERM_HPP

#include <ncurses.h>

#include <chrono>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

void init_displayer();
void displayer(void);
void displayer(int, int, const string&);
void input_display();
void trans_rec_win();
void clear_lines();
int truncater(const string&, int);
string print_time(void);
// ostream& print_time(ostream& output);
string print_date(void);

//#include "Final_Project.cpp"
#include "menu.cpp"
#include "time.cpp"
#include "welcome.cpp"
#include "welcome2.cpp"

#endif
#include "RawTerm.hpp"

string print_time(void);
ostream& print_time(ostream& output);
string print_date(void);

#include <menu.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

void SwitchSub_menu(const char* m, int yy);
static int flag = 0;

/********************-CLASS-**********************/
class SubMenu_Class {
 private:
 protected:
 public:
  enum colour {
    YELLOW = 11,
    BLUE,
    CYAN,
    RED,
    GREEN,
    MAGENTA,
  };

  enum log { enable_log = 21, disable_log };

  enum device { usb0 = 31, usb1, usb2, acm0, acm1 };

  enum time { enable_time = 41, disable_time };

  enum newline { enable_nl = 51, disable_nl };

  enum baudrate { br2400 = 61, br9600, br115200 };
} SubMenuObj;
/******************-FUNCTIONS-*********************/
/*********************-END-************************/

/********************-CLASS-**********************/
class colour : public menu {
 private:
  static int markdown_colour;

 protected:
 public:
  void change_clor_scheme(int i) {
    switch (i) {
      case 0:
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        markdown_colour = 0;
        break;

      case 1:
        init_pair(1, COLOR_BLUE, COLOR_BLACK);
        markdown_colour = 1;
        break;

      case 2:
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        markdown_colour = 2;
        break;

      case 3:
        init_pair(1, COLOR_RED, COLOR_BLACK);
        markdown_colour = 3;
        break;

      case 4:
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        markdown_colour = 4;
        break;

      case 5:
        init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
        markdown_colour = 5;
        break;
    }
  }
  int return_colourStatus() { return markdown_colour; }
  void menu_call(void);
};
/******************-FUNCTIONS-*********************/

int colour::markdown_colour = 0;
/*********************-END-************************/

void menu_call(void);

/********************-CLASS-**********************/

class class_mem : virtual public log_class,
                  virtual public baud,
                  virtual public newline,
                  virtual public colour {
 private:
 protected:
 public:
  time_printing timeObj;
  colour colourfulObj;
  device devObj;
  log_class logObj;
  baud baudObj;
  newline newObj;
} memory;

/******************-FUNCTIONS-*********************/

/*********************-END-************************/
/********************-CLASS-**********************/

class switch_class {
 private:
 protected:
 public:
  void switch_ClassMenu(int i) {
    switch (i) {
      case SubMenuObj.YELLOW:
        memory.colourfulObj.change_clor_scheme(0);
        break;

      case SubMenuObj.BLUE:
        memory.colourfulObj.change_clor_scheme(1);
        break;

      case SubMenuObj.CYAN:
        memory.colourfulObj.change_clor_scheme(2);
        break;

      case SubMenuObj.RED:
        memory.colourfulObj.change_clor_scheme(3);
        break;

      case SubMenuObj.GREEN:
        memory.colourfulObj.change_clor_scheme(4);
        break;

      case SubMenuObj.MAGENTA:
        memory.colourfulObj.change_clor_scheme(5);
        break;

      case SubMenuObj.enable_time:
        memory.timeObj.enable_time();
        break;

      case SubMenuObj.disable_time:
        memory.timeObj.disable_time();
        break;

      case SubMenuObj.enable_log:
        memory.logObj.enable_log();
        break;

      case SubMenuObj.disable_log:
        memory.logObj.enable_log();
        break;

      case SubMenuObj.usb0:
        memory.devObj.switch_dev(0);
        break;

      case SubMenuObj.usb1:
        memory.devObj.switch_dev(1);
        break;

      case SubMenuObj.acm0:
        memory.devObj.switch_dev(2);
        break;

      case SubMenuObj.acm1:
        memory.devObj.switch_dev(3);
        break;

      case SubMenuObj.enable_nl:
        memory.newObj.enable_newline();
        break;

      case SubMenuObj.disable_nl:
        memory.newObj.disable_newline();
        break;

      case SubMenuObj.br2400:
        memory.baudObj.switch_baud(0);
        break;

      case SubMenuObj.br9600:
        memory.baudObj.switch_baud(1);
        break;

      case SubMenuObj.br115200:
        memory.baudObj.switch_baud(2);
        break;
    }
  }
} MENU_Obj;

/******************-FUNCTIONS-*********************/

/*********************-END-************************/

ITEM* my_item[] = {
    new_item("Colour Scheme", " "), new_item("Device", " "),
    new_item("Time Stamp", " "),    new_item("Generate log", " "),
    new_item("Clear Screen", " "),  new_item("Baud Rate", " "),
    new_item("Send Newline", " "),  new_item("EXIT Console", " "),
    new_item("EXIT MENU", " "),     NULL};
ITEM* my_item1[] = {new_item("Yellow", " "), new_item("Blue", " "),
                    new_item("Cyan", " "),   new_item("Red", " "),
                    new_item("Green", " "),  new_item("Magenta", " "),
                    new_item("Exit", " "),   NULL};
ITEM* my_item2[] = {new_item("ttyACM0", " "),
                    new_item("ttyACM1", " "),
                    new_item("USB 0", " "),
                    new_item("USB 1", " "),
                    new_item("USB 2", " "),
                    new_item("Exit", " "),
                    NULL};
ITEM* my_item3[] = {new_item("Enable", " "), new_item("Disable", " "),
                    new_item("Exit", " "), NULL};
ITEM* my_item4[] = {new_item("Enable", " "), new_item("Disable", " "),
                    new_item("Exit", " "), NULL};
ITEM* my_item5[] = {new_item("2400", " "), new_item("9600", " "),
                    new_item("115200", " "), new_item("Exit", " "), NULL};
ITEM* my_item6[] = {new_item("Enable", " "), new_item("Disable", " "),
                    new_item("Exit", " "), NULL};

int dev_item_map(int);
void setting(MENU*, WINDOW*, int);
void select(WINDOW*, MENU*, int, ITEM**, int, int, int = 0);

void menu_call() {
  int i, c;
  ITEM* cur_item;
  WINDOW *my_menu_win, *my_menu_win1, *my_menu_win2, *my_menu_win3,
      *my_menu_win4, *my_menu_win5, *my_menu_win6;

  memory.colourfulObj.change_clor_scheme(
      memory.colourfulObj.return_colourStatus());
  init_pair(2, COLOR_GREEN, COLOR_BLACK);

  /* Initialize items */
  MENU* my_menu = new_menu(my_item);

  /* Set fore ground and back ground of the menu */
  set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
  set_menu_back(my_menu, COLOR_PAIR(2));
  set_menu_format(my_menu, 1, 9);
  menu_opts_off(my_menu, O_SHOWDESC);

  /*Create the window to be associated with the menu*/
  my_menu_win = newwin(5, 149, 0, 15);
  keypad(my_menu_win, TRUE);

  /*Set main window and sub window*/
  set_menu_win(my_menu, my_menu_win);
  set_menu_sub(my_menu, derwin(my_menu_win, 0, 0, 2, 1));
  set_menu_mark(my_menu, " * ");

  /* Post the menu */
  mvprintw(LINES - 3, 3, "Press <ENTER> to see the option selected");
  mvprintw(LINES - 2, 3, "Up,Down,Left & Right arrow keys to navigate ");
  post_menu(my_menu);
  refresh();
  wrefresh(my_menu_win);
  while (c = wgetch(my_menu_win)) switch (c) {
      case KEY_LEFT:
        menu_driver(my_menu, REQ_LEFT_ITEM);
        break;
      case KEY_RIGHT:
        menu_driver(my_menu, REQ_RIGHT_ITEM);
        break;
      case 10: /* Enter */
        move(20, 0);
        clrtoeol();
        mvprintw(20, 0, "Item selected is : %s",
                 item_name(current_item(my_menu)));
        if (!strncmp("EXIT MENU", item_name(current_item(my_menu)), 6)) {
          unpost_menu(my_menu);
          for (int i = 0; i < 9; ++i) free_item(my_item[i]);
          free_menu(my_menu);
          werase(my_menu_win);
          wrefresh(my_menu_win);

          move(20, 0);
          clrtoeol();
          return;
        } else if (!strcmp(item_name(current_item(my_menu)), "EXIT Console")) {
          unpost_menu(my_menu);
          for (int i = 0; i < 9; ++i) free_item(my_item[i]);
          free_menu(my_menu);
          endwin();
          exit(EXIT_SUCCESS);
        } else if (!strcmp(item_name(current_item(my_menu)), "Clear Screen")) {
          mvprintw(20, 0, "Item selected is : %s",
                   item_name(current_item(my_menu)));
          flag = 1;
        }

        else if (!strncmp("Col", item_name(current_item(my_menu)), 3))
          select(my_menu_win1, my_menu, 7, my_item1,
                 memory.colourfulObj.return_colourStatus(), 16);

        else if (!strncmp("Dev", item_name(current_item(my_menu)), 3))
          select(my_menu_win2, my_menu, 6, my_item2,
                 dev_item_map(memory.devObj.get_curr_dev()), 33);
#define timeo 1
        else if (!strncmp("Tim", item_name(current_item(my_menu)), 3))
          select(my_menu_win3, my_menu, 3, my_item3,
                 memory.timeObj.get_enable_status() ? 0 : 1, 50, timeo);
#define log 2
        else if (!strncmp("Gen", item_name(current_item(my_menu)), 3))
          select(my_menu_win4, my_menu, 3, my_item4,
                 memory.logObj.get_log_status() ? 0 : 1, 67, log);
#define newline 3
        else if (!strncmp("Send", item_name(current_item(my_menu)), 4))
          select(my_menu_win6, my_menu, 3, my_item6,
                 memory.newObj.get_nl_status() ? 0 : 1, 118, newline);

        else if (!strncmp("Baud", item_name(current_item(my_menu)), 4))
          select(my_menu_win5, my_menu, 4, my_item5,
                 memory.baudObj.get_baud_idx(), 101);
    }
}

int dev_item_map(int dev_idx) {
  switch (dev_idx) {
    case 0:
      return 2;
    case 1:
      return 3;
    case 2:
      return 0;
    case 3:
      return 1;
  }
  return -1;
}

void setting(MENU* m, WINDOW* w) {
  set_menu_fore(m, COLOR_PAIR(1) | A_REVERSE);
  set_menu_back(m, COLOR_PAIR(2));
  set_menu_format(m, 3, 1);
  menu_opts_off(m, O_SHOWDESC);
  keypad(w, TRUE);
  set_menu_win(m, w);
  set_menu_sub(m, derwin(w, 0, 12, 0, 0));
  set_menu_mark(m, " * ");
  post_menu(m);
  refresh();
  wrefresh(w);
}

void select(WINDOW* w, MENU* main_menu, int row, ITEM** it, int sel_idx,
            int x_axis, int yy) {
  int d;

  unpost_menu(main_menu);
  MENU* m = new_menu(it);

  w = newwin(4, 16, 4, x_axis);
  setting(m, w);
  set_current_item(m, it[sel_idx]);

  while (d = wgetch(w)) switch (d) {
      case KEY_UP:
        menu_driver(m, REQ_UP_ITEM);
        break;
      case KEY_DOWN:
        menu_driver(m, REQ_DOWN_ITEM);
        break;
      case 10:
        move(20, 0);
        clrtoeol();
        mvprintw(20, 0, "Item selected is : %s", item_name(current_item(m)));
        refresh();
        /*
         *TODOO
         */
        if (!strcmp(item_name(current_item(m)), "EXIT Console")) {
          exit(EXIT_SUCCESS);
        }
        SwitchSub_menu(item_name(current_item(m)), yy);
      case 'q':
        werase(w);
        wrefresh(w);
        unpost_menu(m);
        for (int i = 0; i < row; ++i) free_item(it[i]);
        free_menu(m);
        post_menu(main_menu);
        return;
    }

  mvprintw(20, 20, "end_of_line");
}

void SwitchSub_menu(const char* m, int yy) {
  if (!strcmp(m, "Yellow")) MENU_Obj.switch_ClassMenu(SubMenuObj.YELLOW);
  if (!strcmp(m, "Blue")) MENU_Obj.switch_ClassMenu(SubMenuObj.BLUE);
  if (!strcmp(m, "Cyan")) MENU_Obj.switch_ClassMenu(SubMenuObj.CYAN);
  if (!strcmp(m, "Green")) MENU_Obj.switch_ClassMenu(SubMenuObj.GREEN);
  if (!strcmp(m, "Red")) MENU_Obj.switch_ClassMenu(SubMenuObj.RED);
  if (!strcmp(m, "Magenta")) MENU_Obj.switch_ClassMenu(SubMenuObj.MAGENTA);

  if (!strcmp(m, "ttyACM0")) MENU_Obj.switch_ClassMenu(SubMenuObj.acm0);
  if (!strcmp(m, "ttyACM1")) MENU_Obj.switch_ClassMenu(SubMenuObj.acm1);
  if (!strcmp(m, "USB 0")) MENU_Obj.switch_ClassMenu(SubMenuObj.usb0);
  if (!strcmp(m, "USB 1")) MENU_Obj.switch_ClassMenu(SubMenuObj.usb1);
  if (!strcmp(m, "USB 2")) MENU_Obj.switch_ClassMenu(SubMenuObj.usb2);

  if (!strcmp(m, "2400")) MENU_Obj.switch_ClassMenu(SubMenuObj.br2400);
  if (!strcmp(m, "9600")) MENU_Obj.switch_ClassMenu(SubMenuObj.br9600);
  if (!strcmp(m, "115200")) MENU_Obj.switch_ClassMenu(SubMenuObj.br115200);

  if ((!strcmp(m, "Enable")) && yy == 1) {
    MENU_Obj.switch_ClassMenu(SubMenuObj.enable_time);
  }
  if ((!strcmp(m, "Disable")) && yy == 1) {
    MENU_Obj.switch_ClassMenu(SubMenuObj.disable_time);
  }

  if ((!strcmp(m, "Enable")) && (yy == 3)) {
    MENU_Obj.switch_ClassMenu(SubMenuObj.enable_nl);
  }
  if ((!strcmp(m, "Disable")) && (yy == 3)) {
    MENU_Obj.switch_ClassMenu(SubMenuObj.disable_nl);
  }

  if ((!strcmp(m, "Enable")) && (yy == 2)) {
    MENU_Obj.switch_ClassMenu(SubMenuObj.enable_log);
  }
  if ((!strcmp(m, "Disable")) && (yy == 2)) {
    MENU_Obj.switch_ClassMenu(SubMenuObj.disable_log);
  }

  refresh();
}
#ifndef MENU_CPP
#define MENU_CPP

#include "RawTerm.hpp"
namespace fs = std::filesystem;

void trans_rec_win();
void menu_call();
/********************-CLASS-**********************/
class menu {
 private:
 protected:
 public:
  void display_menu() {}
};
/******************-FUNCTIONS-*********************/
/*********************-END-************************/

/********************-CLASS-**********************/
class time_printing : public menu {
 private:
  static int time_enable;

 protected:
 public:
  void enable_time();
  void disable_time();
  int get_enable_status();
};
/******************-FUNCTIONS-*********************/
int time_printing::time_enable = 0;
void time_printing::enable_time() { time_enable = 1; }
void time_printing::disable_time() { time_enable = 0; }
int time_printing::get_enable_status() { return time_enable; }
/*********************-END-************************/

time_printing timeObj;
/********************-CLASS-**********************/
class device : public menu {
 private:
  int device_idx;

 protected:
 public:
  device();
  ofstream outy;
  void write(char* str);
  void display_menu();
  void switch_dev(int i);
  int get_curr_dev();
};
/******************-FUNCTIONS-*********************/
device::device() : device_idx(0) {}
void device::switch_dev(int i) {
  device_idx = i;
  switch (i) {
    case 0:
      if (outy) outy.close();
      outy.open("/dev/ttyUSB0", ios::binary | ios::out);
      break;

    case 1:
      if (outy) outy.close();
      outy.open("/dev/ttyUSB1", ios::binary | ios::out);
      break;

    case 2:
      if (outy) outy.close();
      outy.open("/dev/ttyACM0", ios::binary | ios::out);
      break;

    case 3:
      if (outy) outy.close();
      outy.open("/dev/ttyACM1", ios::binary | ios::out);
      break;
  }
}
void device::display_menu() { cout << "device called display_menu"; }
void device::write(char* str) { outy << str << endl; }
int device::get_curr_dev() { return device_idx; }
/*********************-END-************************/

/********************-CLASS-**********************/
class log_class : public device {
 private:
  static int log_generation_status;
  static int open;
  ofstream logan;
  int num_logs(const string&, const string&);

 protected:
 public:
  void enable_log();
  void disable_log();
  int get_log_status();
  void open_file();
  void generate_log(const char* str);
};
/******************-FUNCTIONS-*********************/
int log_class::open = 0;
int log_class::log_generation_status = 0;
int log_class::num_logs(const string& dir, const string& file) {
  int file_count = 0;

  for (auto& p : fs::directory_iterator(dir)) {
    string filename = p.path().filename();
    if (!filename.compare(0, file.size(), file)) file_count++;
  }

  return file_count;
}

void log_class::enable_log() { log_generation_status = 1; }
void log_class::disable_log() { log_generation_status = 0; }
int log_class::get_log_status() { return log_generation_status; }
void log_class::open_file() {
  if (open == 0) {
    const string LOGS_DIR = "logs";
    string str_date = print_date();
    fs::create_directory(LOGS_DIR);
    fs::path log_filepath = LOGS_DIR;
    int n = num_logs(LOGS_DIR, str_date);
    log_filepath /= str_date + "_" + to_string(n);
    logan.open(log_filepath.c_str(), ios::out | ios::binary);
  }
  open++;
}
void log_class::generate_log(const char* str) {
  open_file();
  logan << str << endl;
}
/*********************-END-************************/
// TODO
log_class logObj;
/********************-CLASS-**********************/
class ip_file : public device {
 private:
 protected:
 public:
  void file_input();
  void display_menu();
};
/******************-FUNCTIONS-*********************/
void ip_file::file_input() {
  trans_rec_win();
  /*
  if (timeObj.get_enable_status()) {
    print_time();
    cout << "\t";
  } else
    cout << "\t\t";

  cin.getline(str, 30, '\n');

  EXIT on EOF (aka ^D)
  if (cin.eof()) {
    cout << endl;
    exit(EXIT_SUCCESS);
  }

  if (strcmp(str, "__MENU")) {
    write(str);
    if (logObj.get_log_status()) {
      logObj.generate_log(str);
    }
  } else
    menu_call();
  */
}
void ip_file::display_menu() { cout << "device called display_menu"; }
/*********************-END-************************/

/********************-CLASS-**********************/

class baud {
 private:
  static int baud_status;
  int baud_idx;

 protected:
 public:
  void enable_baud();
  void disable_baud();
  int get_baud_status();
  void switch_baud(int i);
  int get_baud_idx();
};
/******************-FUNCTIONS-*********************/
int baud::baud_status;

void baud::enable_baud() { baud_status = 1; }
void baud::disable_baud() { baud_status = 0; }
int baud::get_baud_status() { return baud_status; }
void baud::switch_baud(int i) {
  baud_idx = i;
  switch (i) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
  }
}
int baud::get_baud_idx() { return baud_idx; }
/*********************-END-************************/

/********************-CLASS-**********************/
class newline {
 private:
  static int newline_status;

 protected:
 public:
  void enable_newline();
  void disable_newline();
  int get_nl_status(void);
};
/******************-FUNCTIONS-*********************/
int newline::newline_status;

void newline::enable_newline() { newline_status = 1; }
void newline::disable_newline() { newline_status = 0; }
int newline::get_nl_status(void) { return newline_status; }
/*********************-END-************************/

#include "Final_Project.cpp"
#endif  // MENU_CPP
#include "RawTerm.hpp"

void wlkm();
void term();
void menu_call(void);

int main() {
  system("clear");
  wlkm();

  term();
  return 0;
}

void term() {
  device dev;
  dev.switch_dev(1);

  ip_file ip;
  ip.file_input();
}
string print_time(void) {
  const auto p1 = system_clock::now();

  auto millisecs = duration_cast<milliseconds>(p1.time_since_epoch());
  auto secs = duration_cast<seconds>(millisecs);
  millisecs -= duration_cast<milliseconds>(secs);

  time_t time_now = system_clock::to_time_t(p1);
  // cout << put_time(localtime(&time_now), "%T.") << setfill('0') << setw(3)
  //   << millisecs.count();

  struct tm* timey;
  string tempo;
  stringstream text;

  timey = localtime(&time_now);
  text << put_time(timey, "%T.") << setfill('0') << setw(3)
       << millisecs.count();

  tempo = text.str();

  return tempo;
}
ostream& print_time(ostream& output) {
  const auto p1 = system_clock::now();

  auto millisecs = duration_cast<milliseconds>(p1.time_since_epoch());
  auto secs = duration_cast<seconds>(millisecs);
  millisecs -= duration_cast<milliseconds>(secs);

  time_t time_now = system_clock::to_time_t(p1);

  output << put_time(localtime(&time_now), "%T.") << setfill('0') << setw(3)
         << millisecs.count();

  return output;
}
string print_date(void) {
  time_t time_now = system_clock::to_time_t(system_clock::now());
  // output << put_time(localtime(&time_now), "%Y%m%d");

  struct tm* timey;
  string tempo;
  stringstream text;

  //  time(&time_now);
  timey = localtime(&time_now);

  text << put_time(timey, "%b_%d_%Y");
  tempo = text.str();

  //  cout << tempo.c_str();

  return tempo;
}

void wlkm() {
  initscr();
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  attron(A_BOLD);
  attron(COLOR_PAIR(3));
  mvprintw(15, 5,
           "###################################################################"
           "##################----WELCOME----##################################"
           "###############################################");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(1));
  mvprintw(20, 60,
           "%%%%%%%%%%%%%%%%------THIS PROGRAM EMULATES SERIAL TRMINAL IN "
           "C++------%%%%%%%%%%%%%%%%");
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(2));
  mvprintw(27, 10, "1.Colour Scheme -> It changes colour of menu.");
  mvprintw(29, 10, "2.Device        -> Changes USB device to send characters");
  mvprintw(31, 10, "3.Time Stamp    -> Generates time stamp");
  mvprintw(33, 10, "4.Generate Log  -> Generates log");
  mvprintw(35, 10, "5.Clear Screen  -> Clears the Rx Tx window ");
  mvprintw(37, 10, "6.Baud Rate     -> Select a specified baud rate");
  mvprintw(39, 10, "7.Send Newline  -> Send a newline to the device");
  mvprintw(41, 10, "8.EXIT Console  -> Exit Program");
  mvprintw(43, 10, "9.EXIT Menu     -> Exit Menu");
  attroff(COLOR_PAIR(2));
  attroff(A_BOLD);

  refresh();
  char ch;

  ch = cin.get();

  move(15, 5);
  clrtoeol();
  move(20, 60);
  clrtoeol();
  for (int i = 27; i <= 43; i += 2) {
    move(i, 10);
    clrtoeol();
  }

  endwin();
}
/*TODO : curs_border(3X) may be used later*/
#ifndef WELCOME2_CPP
#define WELCOME2_CPP

#include "RawTerm.hpp"
extern time_printing timeObj;
extern log_class logObj;
extern int flag;

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
  mvwprintw(win, 46, 5, "Enter here -->");
  wattroff(win, A_BOLD);

  if (!flag)
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
      if (flag) i = 3;
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
