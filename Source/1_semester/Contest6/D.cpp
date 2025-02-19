#include <iostream>

void Swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int PartitionLomuto(int *arr, int low, int high) {
  int pivot = arr[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      Swap(arr[i], arr[j]);
      i++;
    }
  }
  Swap(arr[i], arr[high]);
  return i;
}

void QuickSort(int *arr, int left, int right) {
  if (left >= right) {
    return;
  }
  int pivot_idx = PartitionLomuto(arr, left, right);
  QuickSort(arr, left, pivot_idx - 1);
  QuickSort(arr, pivot_idx + 1, right);
}

template <typename T> T *Copy(const T *src_begin, const T *src_end, T *dest) {
  while (src_begin != src_end) {
    *dest++ = *src_begin++;
  }
  return dest;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::cin.ignore(1, '\n');

  char **names = new char *[n];
  char **surnames = new char *[n];
  int *marks = new int[n];
  for (int i = 0; i < n; i++) {
    names[i] = new char[1001];
    surnames[i] = new char[1001];
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin.getline(surnames[i], 1000, ' ');
    std::cin.getline(names[i], 1000, ' ');
    std::cin >> a >> b >> c;
    std::cin.ignore(1, '\n');
    marks[i] = a + b + c;
  }

  int *marks_c = new int[n];
  Copy(marks, marks + n, marks_c);

  QuickSort(marks_c, 0, n - 1);

  int min_marks = 0;
  if (n >= 3) {
    min_marks = marks_c[n - 3];
  }
  for (int i = 0; i < n; i++) {
    if (min_marks <= marks[i]) {
      std::cout << surnames[i] << " " << names[i] << '\n';
    }
  }

  for (int i = 0; i < n; i++) {
    delete[] names[i];
    delete[] surnames[i];
  }
  delete[] names;
  delete[] surnames;
  delete[] marks;
  delete[] marks_c;
}
