#include "RawTerm.hpp"
class switch_class;
class colour;

using namespace std;

void menu_call();

class log_class;

/********************-CLASS-**********************/

class time_printing {
 private:
  int time_enable = 1;

 protected:
 public:
  void enable_time() { time_enable = 1; }

  void disable_time() { time_enable = 0; }

  int get_enable_status() { return time_enable; }
};
/******************-FUNCTIONS-*********************/

/*********************-END-************************/

/********************-CLASS-**********************/

class device : public menu {
 private:
 protected:
  time_printing timeObj;

 public:
  /*
  switch_dev need to be called from the menu upon any given choice  ****TODO****
  */
  ofstream outy;
  void switch_dev(int i) {
    switch (i) {
      case 0:
        // if (outf) outf.close();
        outy.open("/dev/ttyUSB0", ios::binary | ios::out);
        break;

      case 1:
        // if (outf) outf.close();
        outy.open("/dev/ttyUSB1", ios::binary | ios::out);
        break;

      case 2:
        // if (outf) outf.close();
        outy.open("/dev/ttyACM0", ios::binary | ios::out);
        break;

      case 3:
        // if (outf) outf.close();
        outy.open("/dev/ttyACM1", ios::binary | ios::out);
        break;
    }
  }

  // TO be called from menu_call           ****TODO*****
  void display_menu() { cout << "device called display_menu"; }

  void write(char *str) {
    outy << str << endl;
    cout << "\tdevice\t";
  }
};

/******************-FUNCTIONS-*********************/

/*********************-END-************************/

/********************-CLASS-**********************/

class log_class : public device {
 private:
  int log_generation_status = 1;

  static int open;
  ofstream logan;

 protected:
 public:
  void enable_log() { log_generation_status = 1; }

  void disable_log() { log_generation_status = 0; }

  int get_log_status() { return log_generation_status; }

  void open_file() {
    if (open == 0) logan.open("chintu", ios::out | ios::binary);
    open++;
  }

  void generate_log(char *str) {
    open_file();
    if (timeObj.get_enable_status()) logan << print_time;  //*****TODO******//
    logan << "\t" << str << endl;
  }
};
/******************-FUNCTIONS-*********************/
int log_class::open = 0;

/*********************-END-************************/

/********************-CLASS-**********************/

class ip_file : public device {
 private:
  log_class logObj;

 protected:
 public:
  void file_input();

  void display_menu() { cout << "device called display_menu"; }
};
/******************-FUNCTIONS-*********************/
void ip_file::file_input() {
  char str[30];

  while (1) {
    cin.getline(str, 30, '\n');

    if (timeObj.get_enable_status()) print_time();

    cout << " affected";
    if (strcmp(str, "__MENU")) {
      write(str);
      if (logObj.get_log_status()) {
        cout << "\tgenerating_log\t";
        logObj.generate_log(str);
      }
    } else
      menu_call();
  }
}
/*********************-END-************************/

/********************-CLASS-**********************/

class baud {
 private:
 protected:
 public:
};
/******************-FUNCTIONS-*********************/

/*********************-END-************************/

/********************-CLASS-**********************/

class newline {
 private:
 protected:
 public:
};

/******************-FUNCTIONS-*********************/

/*********************-END-************************/
