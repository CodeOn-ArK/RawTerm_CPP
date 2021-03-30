#include <chrono>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std::chrono;
using namespace std;
#include "time.cpp"

int main() {
  typedef enum {
    yello,
    trye,
    fjf,
  };

  ofstream fouty;
  fouty.open(print_date().c_str(), ios::out);

  return 0;
}
