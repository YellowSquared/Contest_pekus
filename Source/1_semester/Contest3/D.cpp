#include <iostream>

int main() {
  int* input = new int[9999];
  for (int i = 0; i < 9999; i++) {
    std::cin >> input[i];
  }

  for (int i = 0; i < 9998; i++) {
    for (int j = 0; j < 9998 - i; j++) {
      if (input[j] > input[j + 1]) {
        int tmp = input[j];
        input[j] = input[j + 1];
        input[j + 1] = tmp;
      }
    }
  }

  for (int i = 1; i < 9999; i++) {
    if (input[i - 1] != input[i] && input[i] != input[i + 1]) {
      std::cout << input[i];
      break;
    }
  }

  delete[] input;
}