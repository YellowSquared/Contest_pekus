#include <iostream>

void Swap(int& lhs, int& rhs) {
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

void BubbleSort(int* arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    bool were_permutations = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
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
  int k = 0;
  int count = 0;

  std::cin >> n >> k;

  int* array = new int[k];

  for (int i = 0; i < k; i++) {
    std::cin >> array[i];
  }

  BubbleSort(array, k);

  for (int i = 0; i < k; i++) {
    if (n >= array[i]) {
      n -= array[i];
      count += 1;
    } else {
      break;
    }
  }

  std::cout << count;

  delete[] array;
}