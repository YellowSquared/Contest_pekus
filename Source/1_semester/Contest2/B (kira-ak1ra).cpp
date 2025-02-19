#include <iostream>
#include <cmath>

int main() {
  int n = 0;
  int i = 1;
  int answ = 0;
  std::cin >> n;
  int limit = std::ceil(std::sqrt(n));
  for (; i < limit; i++) {
    if (n % i == 0) {
      answ += 2;
    }
  }
  if (i * i == n) {
    ++answ;
  }
  if (answ == 2) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}
