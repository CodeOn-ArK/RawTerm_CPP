#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

#include "menu.class"
#include "menu_call.h"

void term();
void menu_call(void);

int main() {
  system("clear");
  term();
  return 0;
}

void term() {
  device dev;
  dev.switch_dev(1);

  ip_file ip;
  ip.file_input();
}
