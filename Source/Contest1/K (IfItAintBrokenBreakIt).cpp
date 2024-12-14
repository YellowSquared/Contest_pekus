#include <iostream>

int main() {
  int number1 = 0;
  int number2 = 0;
  std::cin >> number1 >> number2;
  int result = ((number1 - number2) % 2 + (number1 - number2 + 1) % 2 + 1) * number1 / 2 +
               ((number1 - number2) % 2 + (number1 - number2 + 1) % 2 - 1) * number2 / -2;
  std::cout << result;
}
