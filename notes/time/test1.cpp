#include <ctime>
#include <iostream>

int main() {
    time_t now = time(0);            // get current time
    struct tm *ltm = localtime(&now); // convert to local time

    std::cout << "Current time: "
              << 1900 + ltm->tm_year << "-"
              << 1 + ltm->tm_mon    << "-"
              << ltm->tm_mday       << " "
              << ltm->tm_hour       << ":"
              << ltm->tm_min        << ":"
              << ltm->tm_sec
              << std::endl;

    return 0;
}

