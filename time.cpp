#include "RawTerm.hpp"

string print_time(void);
ostream& print_time(ostream& output);
string print_date(void);

string print_time(void) {
  const auto p1 = system_clock::now();

  auto millisecs = duration_cast<milliseconds>(p1.time_since_epoch());
  auto secs = duration_cast<seconds>(millisecs);
  millisecs -= duration_cast<milliseconds>(secs);

  time_t time_now = system_clock::to_time_t(p1);

  struct tm* timey;
  string tempo;
  stringstream text;

  timey = localtime(&time_now);
  text << put_time(timey, "%T.") << setfill('0') << setw(3)
       << millisecs.count();

  tempo = text.str();

  return tempo;
}
ostream& print_time(ostream& output) {
  const auto p1 = system_clock::now();

  auto millisecs = duration_cast<milliseconds>(p1.time_since_epoch());
  auto secs = duration_cast<seconds>(millisecs);
  millisecs -= duration_cast<milliseconds>(secs);

  time_t time_now = system_clock::to_time_t(p1);

  output << put_time(localtime(&time_now), "%T.") << setfill('0') << setw(3)
         << millisecs.count();

  return output;
}
string print_date(void) {
  time_t time_now = system_clock::to_time_t(system_clock::now());

  struct tm* timey;
  string tempo;
  stringstream text;

  timey = localtime(&time_now);

  text << put_time(timey, "%b_%d_%Y");
  tempo = text.str();

  return tempo;
}
