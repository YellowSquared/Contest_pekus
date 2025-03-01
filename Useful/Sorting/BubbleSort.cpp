/*
Данная реализация работает за O(n) в лучшем случае и за O(n ** 2) в худшем. Потребления памяти - M(1).

Как работает данная сортировка пузырьком? 

Возьмем массив {3, 4, 1, 2, 0}. Мы можем представить, что большие по размеру элементы 
постепенно "всплывают" наверх (в конец массива), а меньшие "тонут" (оказываются в начале массива).

Проходы:
{3, 4, 1, 2, 0} -> {3, 1, 0, 2, 4} -> {1, 0, 2, 3, 4} -> {0, 1, 2, 3, 4} -> {0, 1, 2, 3, 4}
                                                                         /
                                                  Последний проход, поскольку перестановок больше не было
*/

#include <iostream>

void Swap(int& a, int& b) {
  int c = a;
  a = b;
  b = c;
}

void BubbleSort(int* arr, int n) {
  bool run = true;
  int arr_len = n;
  while (run) {
    run = false;
    for (int b = 1; b < arr_len; ++b) {
      if (arr[b] < arr[b - 1]) {
        run = true;
        Swap(arr[b], arr[b - 1]);
      }
    }
    --arr_len;
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  BubbleSort(arr, n);
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  delete[] arr;
  return 0;
}
