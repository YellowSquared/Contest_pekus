#include <iostream>
#include <cmath>

int main() {
  int n = 0;
  int i = 1;
  int count = 0;
  std::cin >> n;
  for (; i * i < n; ++i) {
    if (n % i == 0) {
      count += 2;
    }
  }
  if (i * i == n) {
    ++count;
  }
  if (count == 4) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}
