#include <cmath>
#include <fstream>
#include <iostream>
int main() {
  std::ifstream file;
  file.open("input.txt");
  int arr[10000] = { 0 };

  for (int i = 0; i < 10000; i++) {
    file >> arr[i];
  }

  int result[10000] = { 0 };
  int left = 0;
  int right = 9999;

  for (int i = 0; left <= right; i++) {
    if (abs(arr[left]) > abs(arr[right])) {
      result[i] = arr[left] * arr[left];
      left++;
    } else {
      result[i] = arr[right] * arr[right];
      right--;
    }
  }

  for (int i = 9999; i >= 0; i--) {
    std::cout << result[i] << " ";
  }
}