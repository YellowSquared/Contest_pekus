/*
Сортировка вставками работает за O(n ** 2) в худшем случае и М(1) памяти.

Как работает сортировка вставками?

Возьмем массив {3, 4, 1, 2, 0}. Допустим, что некоторая часть массива уже отсортирована, 
а нам нужно вставить некий элемент в эту отсортированную часть. По итогу, мы можем брать
элементы в порядке их нахождения в массиве и вставлять их в отсортированную часть.

Проходы:
{3, 4, 1, 2, 0} -> {3, 4, 1, 2, 0} -> {3, 1, 4, 2, 0} -> {1, 3, 2, 4, 0} -> {1, 2, 3, 0, 4}
                /                     {1, 3, 4, 2, 0}    {1, 2, 3, 4, 0}    {1, 2, 0, 3, 4}
          Нет перестановок,                                                 {1, 0, 2, 3, 4}
          т.к. 3 < 4                                                        {0, 1, 2, 3, 4}
*/

#include <iostream>

void Swap(int& a, int& b) {
  int c = a;
  a = b;
  b = c;
}

void InsertionSort(int* arr, size_t len) {
  size_t arr_pointer = 0;
  for (int i = 1; i < len; ++i) {
    arr_pointer = i - 1;
    while (arr_pointer >= 0 && arr[arr_pointer] > arr[arr_pointer + 1]) {
      Swap(arr[arr_pointer], arr[arr_pointer + 1]);
      --arr_pointer;
    }
  }
}

int main() {
  int n = 1;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  delete[] arr;
  return 0;
}
