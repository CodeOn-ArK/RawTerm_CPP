
void wlkm() {
  initscr();
  start_color();
  mvprintw(30, 80, "      ______");
  mvprintw(31, 80, "  ___/_  __/");
  mvprintw(32, 80, " / __// /");
  mvprintw(34, 80, "/_/  /_/");
  mvprintw(30, 70, "   ___             ______");
  mvprintw(31, 70, "  / _ \___ __    _/_  __/__ ______ _  ");
  mvprintw(31, 70, " / , _/ _ `/ |/|/ // / / -_) __/  ' \ ");
  mvprintw(31, 70, "/_/|_|\_,_/|__,__//_/  \__/_/ /_/_/_/");
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
