#include <iostream>

int main() {
  int x = 0;
  std::cin >> x;
  std::cout << "The next number for the number " << x << " is " << x + 1 << '.';
  std::cout << std::endl;
  std::cout << "The previous number for the number " << x << " is " << x - 1 << '.';
  std::cout << std::endl;
  return 0;
}
