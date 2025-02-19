#include <iostream>

void Merge(int* arr, int left, int mid, int right) {
  int l = mid - left + 1;
  int r = right - mid;

  int* half_l = new int[l];
  int* half_r = new int[r];

  for (int i = 0; i < l; i++) {
    half_l[i] = arr[left + i];
  }
  for (int j = 0; j < r; j++) {
    half_r[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0;
  int pt = left;

  while (i < l && j < r) {
    if (half_l[i] <= half_r[j]) {
      arr[pt] = half_l[i];
      i++;
    } else {
      arr[pt] = half_r[j];
      j++;
    }
    pt++;
  }

  for (; i < l; i++, pt++) {
    arr[pt] = half_l[i];
  }

  for (; j < r; j++, pt++) {
    arr[pt] = half_r[j];
  }

  delete[] half_r;
  delete[] half_l;
}

void MergeSort(int* arr, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  MergeSort(arr, left, mid);
  MergeSort(arr, mid + 1, right);
  Merge(arr, left, mid, right);
}

int main() {
  int n = 0;

  std::cin >> n;

  int* arr = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  MergeSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  delete[] arr;
}