#include <iostream>

int main() {
  int n = 0;
  int a = 0;
  int b = 0;
  std::cin >> n;
  bool is_start = false;
  bool is_end = false;
  int answ = 0;
  for (int i = 0; i < n; ++i) {
    if (is_start) {
      a = b;
      std::cin >> b;
      if (a != b - 1 && !(is_end)) {
        answ = a + 1;
        is_end = true;
      }
    } else {
      std::cin >> b;
      is_start = true;
      if (b != 0) {
        answ = 0;
        is_end = true;
        is_start = true;
      }
    }
  }
  std::cout << answ;
  return 0;
}
