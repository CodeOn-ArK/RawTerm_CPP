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
void print_time(void);
ostream& print_time(ostream& output);
string print_date(void);

//#include "Final_Project.cpp"
#include "menu.cpp"
#include "time.cpp"
#include "welcome.cpp"
#include "welcome2.cpp"

#endif
