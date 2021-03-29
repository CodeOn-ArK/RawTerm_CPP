#include "RawTerm.hpp"

void print_time(void) {
  const auto p1 = system_clock::now();

  /* This is a workaround as `struct tm' from <ctime> doesn't seem to have a
   * field for milliseconds. Here time_since_epoch() will give us the unix epoch
   * time which has been constantly ticking since 00:00:00 UTC on 1 January 1970
   * (an arbitrary date) and is therefore a huge number. We're interested in
   * only extracting the milliseconds following the last second, so we first
   * represent it fully in milliseconds and then take out the number of
   * milliseconds uptil the last second so we'll be left with just the number of
   * milliseconds following the last second.
   */

  auto millisecs = duration_cast<milliseconds>(p1.time_since_epoch());
  auto secs = duration_cast<seconds>(millisecs);
  millisecs -= duration_cast<milliseconds>(secs);

  time_t time_now = system_clock::to_time_t(p1);

  /* Now print the local time and append the number of milliseconds after a
   * decimal point to make it look like it's the decimal part of the seconds
   * field even though it's not.
   */
  cout << put_time(localtime(&time_now), "%T.") << setfill('0') << setw(3)
       << millisecs.count();
  //
}

ostream& print_time(ostream& output) {
  const auto p1 = system_clock::now();

  /* This is a workaround as `struct tm' from <ctime> doesn't seem to have a
   * field for milliseconds. Here time_since_epoch() will give us the unix epoch
   * time which has been constantly ticking since 00:00:00 UTC on 1 January 1970
   * (an arbitrary date) and is therefore a huge number. We're interested in
   * only extracting the milliseconds following the last second, so we first
   * represent it fully in milliseconds and then take out the number of
   * milliseconds uptil the last second so we'll be left with just the number of
   * milliseconds following the last second.
   */

  auto millisecs = duration_cast<milliseconds>(p1.time_since_epoch());
  auto secs = duration_cast<seconds>(millisecs);
  millisecs -= duration_cast<milliseconds>(secs);

  time_t time_now = system_clock::to_time_t(p1);

  /* Now print the local time and append the number of milliseconds after a
   * decimal point to make it look like it's the decimal part of the seconds
   * field even though it's not.
   */
  output << put_time(localtime(&time_now), "%T.") << setfill('0') << setw(3)
         << millisecs.count();

  return output;
}

ostream& print_date(ostream& output) {
  time_t time_now = system_clock::to_time_t(system_clock::now());
  output << put_time(localtime(&time_now), "%Y%m%d");

  return output;
}
