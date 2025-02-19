#include <iostream>
int main() {
  int mat1[3][3];
  int mat2[3][3];
  int result[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cin >> mat1[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cin >> mat2[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int temp = 0;
      for (int t = 0; t < 3; t++) {
        temp += mat1[i][t] * mat2[t][j];
      }
      result[i][j] = temp;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << result[i][j] << " ";
    }
    std::cout << "\n";
  }
}
