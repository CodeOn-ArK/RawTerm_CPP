#include <chrono>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void print_time(void) {
    const auto p1 = system_clock::now();
    time_t time_now = system_clock::to_time_t(p1);

    /* TODO: Print milliseconds as well */
    cout << put_time(localtime(&time_now), "%T ");
}
