#include <unistd.h>

const useconds_t DELAY_TIME = 5000000;

void wlkm() {
  initscr();
  curs_set(0);
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  assume_default_colors(COLOR_YELLOW, COLOR_BLACK);
  attron(A_BLINK);
  mvprintw(10, 85, "      ______");
  mvprintw(11, 85, "  ___/_  __/");
  attron(COLOR_PAIR(1));
  mvprintw(12, 85, " / __// /");
  mvprintw(13, 85, "/_/  /_/");
  refresh();
  // usleep(DELAY_TIME / 1.5);
  for (int i = 10; i <= 13; i++) {
    move(i, 0);
    clrtoeol();
  }
  attroff(A_BLINK);
  attron(COLOR_PAIR(2));
  mvprintw(10, 75, "   ___             ______");
  attron(COLOR_PAIR(1));
  mvprintw(11, 75, "  / _ \\___ __    _/_  __/__ ______ _  ");
  attron(COLOR_PAIR(3));
  mvprintw(12, 75, " / , _/ _ `/ |/|/ // / / -_) __/  ' \\ ");
  attron(COLOR_PAIR(4));
  mvprintw(13, 75, "/_/|_|\\_,_/|__,__//_/  \\__/_/ /_/_/_/");
  refresh();
  //  usleep(DELAY_TIME);
  for (int i = 10; i <= 13; i++) {
    move(i, 0);
    clrtoeol();
  }
  assume_default_colors(COLOR_WHITE, COLOR_BLACK);
  attroff(COLOR_PAIR(1));
  attroff(A_BLINK);
  refresh();
  attron(A_BOLD);
  attron(COLOR_PAIR(3));
  mvprintw(
      13, 62,
      "###################################################################");
  mvprintw(
      14, 62,
      "                                                                   ");
  mvprintw(
      15, 62,
      "#                         ---WELCOME----                          #");
  mvprintw(
      16, 62,
      "                                                                   ");
  mvprintw(
      17, 62,
      "###################################################################");
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

  (void)ch;
  endwin();
}
