#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  char *p[10];

  p[0] = new char[8];
  p[1] = new char[8];

  p[2] = p[0];
  int y;
  y = 5;
  for (int i = 0; i < y; i++) {
    cin >> *(p[0]++);
    //    cout << *(p[0]++) << "\t";
  }
  p[0] = p[2];
  cout << p[0];
  strcat(p[1], p[0]);
  cout << p[1];
  return 0;
}
