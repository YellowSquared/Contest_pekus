#include <iostream>
#include <cmath>

int main() {
  int time_1_h = 0;
  int time_1_m = 0;
  int time_1_s = 0;
  int time_2_h = 0;
  int time_2_m = 0;
  int time_2_s = 0;
  int time = 0;
  std::cin >> time_1_h >> time_1_m >> time_1_s;
  std::cin >> time_2_h >> time_2_m >> time_2_s;
  time = time_1_h * 3600 + time_1_m * 60 + time_1_s;
  time = std::abs(time - (time_2_h * 3600 + time_2_m * 60 + time_2_s));
  std::cout << time << std::endl;
  return 0;
}
