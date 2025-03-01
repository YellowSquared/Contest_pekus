/*
Работает за O(n ** 2). Потребления памяти - M(1).

Как работает сортировка выбором? 
Берём самый маленький элемент и кидаем его в начало списка. Берём самый маленький за исключением первого,
и кидаем на 2-ую позицию. Так делаем до конца списка

Проходы:
{3, 4, 1, 2, 0} -> {0, 4, 1, 2, 3} -> {0, 1, 4, 2, 3} -> {0, 1, 2, 4, 3} -> {0, 1, 2, 3, 4}
*/

#include <iostream>

void Swap(int& a, int& b) {
  int c = a;
  a = b;
  b = c;
}

void SelectionSort(int* arr, size_t length) {
  int arr_pointer = length - 1;
  int k = 0;
  for (int i = 0; i < length; ++i) {
    k = 0;
    for (int j = 0; j <= arr_pointer; ++j) {
      if (arr[k] <= arr[j]) {
        k = j;
      }
    }
    Swap(arr[arr_pointer], arr[k]);
    --arr_pointer;
  }
}

int main() {
  int n = 1;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  SelectionSort(arr, n);
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  return 0;
}
