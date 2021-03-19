#include <fstream>
#include <iostream>

int main() {
  ofstream outf;

  cout << "Enter Item Details\n";
  char name[30];
  cin >> name;

  outf.open("/dev/ttyUSB0", ios::binary | ios::nocreate | ios::out);

  if (!outf) cout << "Open failed\n";

  outf << name << "\n";

  cout << "Enter Item cost\n ";
  float cost;
  cin >> cost;

  outf << cost << endl;
  outf.close();

  return 0;
}
