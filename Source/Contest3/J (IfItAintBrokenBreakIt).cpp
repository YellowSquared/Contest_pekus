#include <iostream>
#include <cmath>

int main() {
  int n = 0;
  int time1 = 0;
  int time2 = 0;
  std::cin >> n >> time1 >> time2;
  int amount_of_sheets1 = (n - 1) * time2 / (time1 + time2);
  int amount_of_sheets2 = (n - 1) * time1 / (time1 + time2);
  int result = 0;
  if (time1 > time2) {
    result += time2;
  } else {
    result += time1;
  }
  if (amount_of_sheets1 + amount_of_sheets2 != (n - 1)) {
    if ((amount_of_sheets1 + 1) * time1 > (amount_of_sheets2 + 1) * time2) {
      amount_of_sheets2 += 1;
    } else {
      amount_of_sheets1 += 1;
    }
  }
  if (amount_of_sheets1 * time1 > amount_of_sheets2 * time2) {
    result += amount_of_sheets1 * time1;
  } else {
    result += amount_of_sheets2 * time2;
  }
  std::cout << result;
  return 0;
}
