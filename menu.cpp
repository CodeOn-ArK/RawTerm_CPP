#include "RawTerm.hpp"
#include <filesystem>
namespace fs = std::filesystem;

void menu_call();
/********************-CLASS-**********************/
class menu {
 private:
 protected:
 public:
  void display_menu() {}
};
/******************-FUNCTIONS-*********************/
/*********************-END-************************/

/********************-CLASS-**********************/
class time_printing {
 private:
  static int time_enable;

 protected:
 public:
  void enable_time();
  void disable_time();
  int get_enable_status();
};
/******************-FUNCTIONS-*********************/
int time_printing::time_enable = 0;
void time_printing::enable_time() { time_enable = 1; }
void time_printing::disable_time() { time_enable = 0; }
int time_printing::get_enable_status() { return time_enable; }
/*********************-END-************************/

/********************-CLASS-**********************/
class device : public menu {
 private:
 protected:
  time_printing timeObj;

 public:
  ofstream outy;
  void write(char *str);
  void display_menu();
  void switch_dev(int i);
};
/******************-FUNCTIONS-*********************/
void device::switch_dev(int i) {
  switch (i) {
    case 0:
      if (outy) outy.close();
      outy.open("/dev/ttyUSB0", ios::binary | ios::out);
      break;

    case 1:
      if (outy) outy.close();
      outy.open("/dev/ttyUSB1", ios::binary | ios::out);
      break;

    case 2:
      if (outy) outy.close();
      outy.open("/dev/ttyACM0", ios::binary | ios::out);
      break;

    case 3:
      if (outy) outy.close();
      outy.open("/dev/ttyACM1", ios::binary | ios::out);
      break;
  }
}
void device::display_menu() { cout << "device called display_menu"; }
void device::write(char *str) { outy << str << endl; }
/*********************-END-************************/

/********************-CLASS-**********************/
class log_class : public device {
 private:
  static int log_generation_status;
  static int open;
  ofstream logan;
  int num_logs(const string&, const string&);

 protected:
 public:
  void enable_log();
  void disable_log();
  int get_log_status();
  void open_file();
  void generate_log(char *str);
};
/******************-FUNCTIONS-*********************/
int log_class::open = 0;
int log_class::log_generation_status = 0;
int log_class::num_logs(const string& dir, const string& file) {
  int file_count = 0;

  for(auto& p : fs::directory_iterator(dir)) {
    string filename = p.path().filename();
    if (!filename.compare(0, file.size(), file))
        file_count++;
  }

  return file_count;
}

void log_class::enable_log() { log_generation_status = 1; }
void log_class::disable_log() { log_generation_status = 0; }
int log_class::get_log_status() { return log_generation_status; }
void log_class::open_file() {
  if (open == 0) {
    const string LOGS_DIR = "logs";
    string str_date = print_date();
    fs::create_directory(LOGS_DIR);
    fs::path log_filepath = LOGS_DIR;
    int n = num_logs(LOGS_DIR, str_date);
    log_filepath /= str_date + "_" + to_string(n);
    logan.open(log_filepath.c_str(), ios::out | ios::binary);
  }
  open++;
}
void log_class::generate_log(char *str) {
  open_file();

  if (timeObj.get_enable_status()) {
    logan << print_time << "\t" << str << endl;
  } else
    logan << "\t\t" << str << endl;

  // if (timeObj.get_enable_status()) logan << print_time;  //*****TODO******//
}
/*********************-END-************************/

/********************-CLASS-**********************/
class ip_file : public device {
 private:
  log_class logObj;

 protected:
 public:
  void file_input();
  void display_menu();
};
/******************-FUNCTIONS-*********************/
void ip_file::file_input() {
  char str[30];

  while (1) {
    if (timeObj.get_enable_status()) {
      print_time();
      cout << "\t";
    } else
      cout << "\t\t";

    cin.getline(str, 30, '\n');

    if (strcmp(str, "__MENU")) {
      write(str);
      if (logObj.get_log_status()) {
        logObj.generate_log(str);
      }
    } else
      menu_call();
  }
}
void ip_file::display_menu() { cout << "device called display_menu"; }
/*********************-END-************************/

/********************-CLASS-**********************/

class baud {
 private:
  static int baud_status;

 protected:
 public:
  void enable_baud();
  void disable_baud();
  int get_baud_status();
  void switch_baud(int i);
};
/******************-FUNCTIONS-*********************/
int baud::baud_status;

void baud::enable_baud() { baud_status = 1; }
void baud::disable_baud() { baud_status = 0; }
int baud::get_baud_status() { return baud_status; }
void baud::switch_baud(int i) {
  switch (i) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
  }
}
/*********************-END-************************/

/********************-CLASS-**********************/
class newline {
 private:
  static int newline_status;

 protected:
 public:
  void enable_newline();
  void disable_newline();
  int get_nl_status(void);
};
/******************-FUNCTIONS-*********************/
int newline::newline_status;

void newline::enable_newline() { newline_status = 1; }
void newline::disable_newline() { newline_status = 0; }
int newline::get_nl_status(void) { return newline_status; }
/*********************-END-************************/

#include "Final_Project.cpp"
