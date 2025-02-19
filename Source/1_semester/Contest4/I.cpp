#include <iostream>

void Swap(int& lhs, int& rhs) {
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

void RemainderBubbleSort(int* arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    bool were_permutations = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] % 10 > arr[j + 1] % 10) {
        Swap(arr[j], arr[j + 1]);
        were_permutations = true;
      }
    }
    if (!were_permutations) {
      return;
    }
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  int* arr = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  RemainderBubbleSort(arr, n);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
}