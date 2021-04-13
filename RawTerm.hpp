#ifndef RAWTERM_HPP
#define RAWTERM_HPP

#include <menu.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

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
string print_date(void);

#include "menu.cpp"
#include "time.cpp"
#include "welcome.cpp"
#include "welcome2.cpp"

#endif
