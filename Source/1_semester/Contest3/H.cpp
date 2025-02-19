#include <cmath>
#include <iostream>

int main() {
  double velocity_p = 0;
  double velocity_f = 0;
  double a = 0;

  std::cin >> velocity_p >> velocity_f >> a;
  double l = 0;
  double r = 1;
  double x = 0;
  double t = 0;

  while (fabs((l + r) / 2 - x) > 0.00001) {
    x = (l + r) / 2;
    t = (x / (sqrt(x * x + (a - 1) * (a - 1)) * velocity_p)) +
      ((x - 1) / ((sqrt((x - 1) * (x - 1) + a * a)) * velocity_f));
    if (t < 0) {
      l = x;
    } else {
      r = x;
    }
  }
  std::cout << x;
}
