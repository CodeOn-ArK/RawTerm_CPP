#include <cstring>
#include <iostream>
#include <string>

using namespace std;
/********************-CLASS-**********************/

class conversion {
 private:
 protected:
 public:
  char* str;
  char **partition, **head;
  int len, div_len, rem_len;
  conversion() {
    // str = new char*;
    //*str = new char;
    len = 0;
  }

  conversion(string& s) {
    //    cout << s.size() << endl;

    len = s.size();
    div_len = len / 20;

    //   cout << div_len << endl;
    rem_len = len % 20;

    //  cout << rem_len << endl;
    str = new char[len];

    partition = new char*[div_len];
    head = partition;
    for (int i = 0; i < div_len; i++) {
      //   cout << i << endl;
      *partition = new char[20];
      partition++;
    }
    partition = head;

    for (int i = 0; i < s.size(); i++) {
      str[i] = s[i];
    }

    /*for (int i = 0; i < div_len; i++) {
      *str = s.substr(i, 20);
    }*/
  }

  void call_partition() {
    cout << "\ncalling part\n";
    int t = 65;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 20; j++) {
        **partition = t++;
        cout << **partition << '\t';
        (*partition)++;
      }
      cout << '\n';
      partition++;
    }
  }

  void display() {
    partition = head;
    cout << '\n' << **partition++ << endl;
    cout << **partition << endl;
  }
};

/******************-FUNCTIONS-*********************/

/*********************-END-************************/

int truncater(string& line, int start_col) {
  int inc, col, size = line.size();

  conversion classy(line);
  inc = line.size() / 20;

  for (int col = 0; col < inc; col++) {
    // mvprintw(start_col + col, 0, classy.str[col]);  // line[20 * col
    // + i]);
  }

  return inc;
}

int main() {
  string line = "_hello_1_hello_2_hello_3_hello_4_hello_5";
  conversion c(line);

  c.call_partition();
  c.display();
  return 0;
}
