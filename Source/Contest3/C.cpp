#include <iostream>

void Swap(int& lhs, int& rhs) {
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

void InsertionSort(int* arr, const int size) {
  for (int i = 1; i < size; ++i) {
    for (int j = i; j > 0 and arr[j] < arr[j - 1]; j--) {
      Swap(arr[j], arr[j - 1]);
    }
  }
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

void Input(int* arr, const int size) {
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
}
void Output(int* arr, const int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  int* arr = new int[n];
  Input(arr, n);
  BubbleSort(arr, n);
  Output(arr, n);
  delete[] arr;
}