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
