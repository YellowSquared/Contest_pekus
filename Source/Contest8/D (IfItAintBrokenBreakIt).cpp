#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  if (n == 2) {
    int k1 = 0;
    std::cin >> k1;
    int count1 = 0;
    for (int i = 0; i < k1; i += 1) {
      int temp = 0;
      std::cin >> temp;
      if (temp == 2) {
        count1 += 1;
      } else {
        if (count1) {
          std::cout << 0;
          return 0;
        }
      }
    }
    int k2 = 0;
    std::cin >> k2;
    int count2 = 0;
    for (int i = 0; i < k2; i += 1) {
      int temp = 0;
      std::cin >> temp;
      if (temp == 1) {
        if (count1) {
          std::cout << 0;
          return 0;
        }
        count2 += 1;
      } else {
        if (count2) {
          std::cout << 0;
          return 0;
        }
      }
    }
    while (count1) {
      std::cout << 1 << ' ' << 2 << '\n';
      count1 -= 1;
    }
    while (count2) {
      std::cout << 2 << ' ' << 1 << '\n';
      count2 -= 1;
    }
    return 0;
  }
  int arr[250001];
  int k = 0;
  std::cin >> k;
  for (int i = 0; i < k; i += 1) {
    std::cin >> arr[i];
  }
  int amount = k;
  for (int i = 1; i < n; i += 1) {
    std::cin >> k;
    amount += k;
    for (int j = 0; j < k; j += 1) {
      std::cin >> arr[amount - j - 1];
      std::cout << i + 1 << ' ' << 1 << '\n';
    }
  }
  int amount2 = 0;
  int arr2[250001];
  while (amount) {
    if (arr[amount - 1] == 2) {
      arr2[amount2] = 2;
      amount2 += 1;
    }
    if (arr[amount - 1] == 1) {
      std::cout << 1 << ' ' << 2 << '\n';
      arr2[amount2] = 1;
      amount2 += 1;
      amount -= 1;
    } else {
      std::cout << 1 << ' ' << arr[amount - 1] << '\n';
      amount -= 1;
    }
  }
  int amount3 = 0;
  while (amount2) {
    if (arr2[amount2 - 1] == 1) {
      std::cout << 2 << ' ' << 1 << '\n';
    } else {
      std::cout << 2 << ' ' << 3 << '\n';
      amount3 += 1;
    }
    amount2 -= 1;
  }
  while (amount3) {
    std::cout << 3 << ' ' << 2 << '\n';
    amount3 -= 1;
  }
}
