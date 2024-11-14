#include <cstring>
#include <fstream>
#include <iostream>

template <class T>
void Swap(T& lhs, T& rhs) {
  T tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

template <class T>
void Swap(T&& lhs, T&& rhs) {
  T tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}


int PartitionHoare(char** arr, int low, int high) {
  char* pivot = arr[low];

  int i = low;
  int j = high;

  for (;;) {
    for (; strcmp(arr[i], pivot) < 0;) {
      i++;
    }

    for (; strcmp(arr[j], pivot) > 0;) {
      j--;
    }

    if (i >= j) {
      return j;
    }
    Swap(arr[i], arr[j]);
    i++;
    j--;
  }
}


void QuickSortHoare(char** arr, int low, int high) {
  if (low < high) {
    int piv = PartitionHoare(arr, low, high);

    QuickSortHoare(arr, low, piv);
    QuickSortHoare(arr, piv + 1, high);
  }
}


void Permutate(char* arr, int n, int index, int& pos, char** result) {
  if (index == n) {
    for (int i = 0; i < n; i++) {
      result[pos][i] = arr[i];
    }
    pos++;
    return;
  }

  for (int i = index; i < n; i++) {
    Swap(arr[i], arr[index]);

    Permutate(arr, n, index + 1, pos, result);

    Swap(arr[i], arr[index]);
  }
}

int main() {
  char* inp = new char[9];

  std::cin.getline(inp, 9, '\n');

  int n = static_cast<int>(std::strlen(inp));

  int arrsize = 1;

  for (int i = 1; i <= n; i++) {
    arrsize *= i;
  }

  char** result = new char*[arrsize];
  for (int i = 0; i < arrsize; i++) {
    result[i] = new char[n];
    result[i][0] = 0;
  }

  int pos = 0;
  Permutate(inp, n, 0, pos, result);

  QuickSortHoare(result, 0, n - 1);

  std::ofstream file;
  file.open("output.txt");

  for (int i = 0; i < arrsize - 1; i++) {
    if (result[i][0] != 0 && strcmp(result[i], result[i + 1]) != 0) {
      for (int j = 0; j < n; j++) {
        file << result[i][j];
      }
      file << "\n";
    }
  }

  if (result[arrsize - 1][0] != 0) {
    for (int j = 0; j < n; j++) {
      file << result[arrsize - 1][j];
    }
  }
  file.close();

  delete[] inp;
  for (int i = 0; i < arrsize; i++) {
    delete[] result[i];
  }
  delete[] result;
}