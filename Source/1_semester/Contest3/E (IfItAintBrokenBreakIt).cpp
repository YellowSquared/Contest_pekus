#include <iostream>
#include <cmath>

int main() {
  int matrice1[9];
  int matrice2[9];
  for (int i = 0; i < 9; i += 1) {
    std::cin >> matrice1[i];
  }
  for (int i = 0; i < 9; i += 1) {
    std::cin >> matrice2[i];
  }
  int result[9];
  for (int i = 0; i < 9; i += 1) {
    result[i] = matrice1[i / 3 * 3] * matrice2[i % 3] + matrice1[i / 3 * 3 + 1] * matrice2[i % 3 + 3] +
                matrice1[i / 3 * 3 + 2] * matrice2[i % 3 + 6];
  }
  for (int i = 0; i < 9; i += 1) {
    std::cout << result[i] << " ";
    if (i % 3 == 2) {
      std::cout << "\n";
    }
  }
  return 0;
}
