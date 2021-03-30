#ifndef RAWTERM_HPP
#define RAWTERM_HPP

#include <chrono>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace std::chrono;

void print_time(void);
ostream& print_time(ostream& output);
string print_date(void);

//#include "Final_Project.cpp"
#include "menu.cpp"
#include "time.cpp"

#endif
