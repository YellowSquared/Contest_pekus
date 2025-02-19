#include <iostream>

int main() {
  int common_time = 0;
  int sec = 0;
  int min = 0;
  int hrs = 0;
  std::cin >> common_time;
  common_time = common_time % (24 * 60 * 60);
  hrs = common_time / (60 * 60);
  min = (common_time % (60 * 60)) / 60;
  sec = common_time % 60;
  std::cout << hrs << ':';
  std::cout << min / 10 << min % 10 << ':';
  std::cout << sec / 10 << sec % 10 << std::endl;
  return 0;
}
