#include <fstream>
#include <iostream>
#include <cerrno>
#include <cstring>
using namespace std;

int main() {
  ofstream outf;

  cout << "Enter Item Details\n";
  char name[30];
  cin >> name;


  // Abort if file doesn't exist
  errno = 0;
  ifstream f("/dev/ttyUSB0");
  if (!f.is_open()) {
    cerr << "Error : /dev/ttyUSB0: " << strerror(errno) << endl;
    return EXIT_FAILURE;
  }

  errno = 0;
  outf.open("/dev/ttyUSB0", ios::binary | ios::out);
  if (!outf.is_open()) {
    cerr << "Error : /dev/ttyUSB0: " << strerror(errno) << endl;
    return EXIT_FAILURE;
  }

  outf << name << "\n";

  cout << "Enter Item cost\n ";
  float cost;
  cin >> cost;

  outf << cost << endl;
  outf.close();

  return 0;
}
