#include <iostream>

void QuickSort(int** arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot = arr[high][0];
  int i = low;
  for (int j = low; j <= high; j += 1) {
    if (arr[j][0] <= pivot) {
      int temp = arr[i][0];
      int temp2 = arr[i][1];
      arr[i][0] = arr[j][0];
      arr[i][1] = arr[j][1];
      arr[j][0] = temp;
      arr[j][1] = temp2;
      i += 1;
    }
  }
  QuickSort(arr, low, i - 2);
  QuickSort(arr, i, high);
}

int main() {
  int n = 0;
  std::cin >> n;
  int** arr = new int*[n];
  for (int i = 0; i < n; i += 1) {
    arr[i] = new int[2];
    std::cin >> arr[i][0];
    arr[i][1] = i;
  }
  QuickSort(arr, 0, n - 1);
  int q = 0;
  std::cin >> q;
  int l = 0;
  int r = 0;
  int x = 0;
  for (int i = 0; i < q; i += 1) {
    std::cin >> l;
    l -= 1;
    std::cin >> r;
    r -= 1;
    std::cin >> x;
    int left = 0;
    int right = n - 1;
    while (left < right - 1) {
      int mid = (left + right) / 2;
      if (arr[mid][0] < x) {
        left = mid;
      } else {
        right = mid;
      }
    }
    int start = right;
    if (arr[0][0] >= x) {
      start = 0;
    }
    left = 0;
    right = n - 1;
    while (left < right - 1) {
      int mid = (left + right) / 2;
      if (arr[mid][0] <= x) {
        left = mid;
      } else {
        right = mid;
      }
    }
    int end = left;
    if (arr[n - 1][0] <= x) {
      end = right;
    }
    bool flag = false;
    if (arr[start][0] == x and arr[end][0] == x) {
      left = start;
      right = end;
      while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid][1] > r) {
          right = mid - 1;
        } else if (arr[mid][1] < l) {
          left = mid + 1;
        } else {
          flag = true;
          break;
        }
      }
    }
    if (flag) {
      std::cout << 1;
    } else {
      std::cout << 0;
    }
  }
  for (int i = 0; i < n; i += 1) {
    delete[] arr[i];
  }
  delete[] arr;
}
