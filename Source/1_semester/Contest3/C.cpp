#include <fstream>
#include <iostream>

int main() {
  std::ifstream myfile;
  myfile.open("input.txt");
  int* input = new int[10000];

  for (int i = 0; i < 10000; i++) {
    myfile >> input[i];
  }

  for (int i = 0; i < 9999; i++) {
    for (int j = 0; j < 9999 - i; j++) {
      if (input[j] == 0) {
        int tmp = input[j];
        input[j] = input[j + 1];
        input[j + 1] = tmp;
      }
    }
  }

  for (int i = 0; i <= 9999; i++) {
    std::cout << input[i] << " ";
  }

  delete[] input;
}