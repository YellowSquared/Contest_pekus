#include <cmath>
#include <iostream>

int main() {
  int n = 0;
  int x = 0;
  int y = 0;
  int printed = 1;

  std::cin >> n >> x >> y;

  int time = std::min(x, y);

  int i = 1;

  while (printed < n) {
    if (i % x == 0) {
      printed += 1;
    }
    if (i % y == 0) {
      printed += 1;
    }
    time++;
    i++;
  }

  std::cout << time;
}
