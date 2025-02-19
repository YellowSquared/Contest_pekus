#include <iostream>

void QuickSort(int** arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot = arr[high][0];
  int i = low;
  for (int j = low; j <= high; j += 1) {
    if (arr[j][0] >= pivot) {
      int temp[3] = {arr[i][0], arr[i][1], arr[i][2]};
      arr[i][0] = arr[j][0];
      arr[i][1] = arr[j][1];
      arr[i][2] = arr[j][2];
      arr[j][0] = temp[0];
      arr[j][1] = temp[1];
      arr[j][2] = temp[2];
      i += 1;
    }
  }
  QuickSort(arr, low, i - 2);
  QuickSort(arr, i, high);
}

int BinarySearch(int** arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid][0] > value) {
      left = mid + 1;
    } else if (arr[mid][0] < value) {
      right = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

void Sort(int** arr, int size, int new_element_index) {
  while (new_element_index > 0 and arr[new_element_index][0] > arr[new_element_index - 1][0]) {
    int temp[3] = {arr[new_element_index][0], arr[new_element_index][1], arr[new_element_index][2]};
    arr[new_element_index][0] = arr[new_element_index - 1][0];
    arr[new_element_index][1] = arr[new_element_index - 1][1];
    arr[new_element_index][2] = arr[new_element_index - 1][2];
    arr[new_element_index - 1][0] = temp[0];
    arr[new_element_index - 1][1] = temp[1];
    arr[new_element_index - 1][2] = temp[2];
    new_element_index -= 1;
  }
  while (new_element_index < size - 1 and arr[new_element_index][0] < arr[new_element_index + 1][0]) {
    int temp[3] = {arr[new_element_index][0], arr[new_element_index][1], arr[new_element_index][2]};
    arr[new_element_index][0] = arr[new_element_index + 1][0];
    arr[new_element_index][1] = arr[new_element_index + 1][1];
    arr[new_element_index][2] = arr[new_element_index + 1][2];
    arr[new_element_index + 1][0] = temp[0];
    arr[new_element_index + 1][1] = temp[1];
    arr[new_element_index + 1][2] = temp[2];
    new_element_index += 1;
  }
}

void ReplaceTopElement(int** arr, int** top, int m, int n, int index) {
  arr[top[index][1]][top[index][2]] = 0;
  while (top[index][1] < m - 1 and arr[top[index][1]][top[index][2]] == 0) {
    top[index][1] += 1;
  }
  top[index][0] = arr[top[index][1]][top[index][2]];
  Sort(top, n, index);
}

void ReplaceTop(int** arr, int** top, int m, int n, int value) {
  int temp = BinarySearch(top, n, value);
  if (temp != -1) {
    ReplaceTopElement(arr, top, m, n, temp);
    if (top[temp][0] == value) {
      ReplaceTopElement(arr, top, m, n, temp);
    }
    if (temp < n - 1 and top[temp + 1][0] == value) {
      ReplaceTopElement(arr, top, m, n, temp + 1);
    }
    if (temp > 0 and top[temp - 1][0] == value) {
      ReplaceTopElement(arr, top, m, n, temp - 1);
    }
  }
}

void ReplaceBottomElement(int** arr, int** bottom, int n, int index) {
  arr[bottom[index][1]][bottom[index][2]] = 0;
  while (bottom[index][1] > 0 and arr[bottom[index][1]][bottom[index][2]] == 0) {
    bottom[index][1] -= 1;
  }
  bottom[index][0] = arr[bottom[index][1]][bottom[index][2]];
  Sort(bottom, n, index);
}

void ReplaceBottom(int** arr, int** bottom, int n, int value) {
  int temp = BinarySearch(bottom, n, value);
  if (temp != -1) {
    ReplaceBottomElement(arr, bottom, n, temp);
    if (bottom[temp][0] == value) {
      ReplaceBottomElement(arr, bottom, n, temp);
    }
    if (temp < n - 1 and bottom[temp + 1][0] == value) {
      ReplaceBottomElement(arr, bottom, n, temp + 1);
    }
    if (temp > 0 and bottom[temp - 1][0] == value) {
      ReplaceBottomElement(arr, bottom, n, temp - 1);
    }
  }
}

void ReplaceLeftElement(int** arr, int** left, int m, int n, int index) {
  arr[left[index][1]][left[index][2]] = 0;
  while (left[index][2] < n - 1 and arr[left[index][1]][left[index][2]] == 0) {
    left[index][2] += 1;
  }
  left[index][0] = arr[left[index][1]][left[index][2]];
  Sort(left, m, index);
}

void ReplaceLeft(int** arr, int** left, int m, int n, int value) {
  int temp = BinarySearch(left, m, value);
  if (temp != -1) {
    ReplaceLeftElement(arr, left, m, n, temp);
    if (left[temp][0] == value) {
      ReplaceLeftElement(arr, left, m, n, temp);
    }
    if (temp < m - 1 and left[temp + 1][0] == value) {
      ReplaceLeftElement(arr, left, m, n, temp + 1);
    }
    if (temp > 0 and left[temp - 1][0] == value) {
      ReplaceLeftElement(arr, left, m, n, temp - 1);
    }
  }
}

void ReplaceRightElement(int** arr, int** right, int m, int index) {
  arr[right[index][1]][right[index][2]] = 0;
  while (right[index][2] > 0 and arr[right[index][1]][right[index][2]] == 0) {
    right[index][2] -= 1;
  }
  right[index][0] = arr[right[index][1]][right[index][2]];
  Sort(right, m, index);
}

void ReplaceRight(int** arr, int** right, int m, int value) {
  int temp = BinarySearch(right, m, value);
  if (temp != -1) {
    ReplaceRightElement(arr, right, m, temp);
    if (right[temp][0] == value) {
      ReplaceRightElement(arr, right, m, temp);
    }
    if (temp < m - 1 and right[temp + 1][0] == value) {
      ReplaceRightElement(arr, right, m, temp + 1);
    }
    if (temp > 0 and right[temp - 1][0] == value) {
      ReplaceRightElement(arr, right, m, temp - 1);
    }
  }
}

int main() {
  int m = 0;
  int n = 0;
  std::cin >> m >> n;
  int** arr = new int*[m];
  for (int i = 0; i < m; i += 1) {
    arr[i] = new int[n];
  }
  for (int i = 0; i < m; i += 1) {
    for (int j = 0; j < n; j += 1) {
      std::cin >> arr[i][j];
    }
  }
  int** top = new int*[n];
  int** bottom = new int*[n];
  int** left = new int*[m];
  int** right = new int*[m];
  for (int i = 0; i < n; i += 1) {
    top[i] = new int[3];
    top[i][0] = arr[0][i];
    top[i][1] = 0;
    top[i][2] = i;
  }
  for (int i = 0; i < n; i += 1) {
    bottom[i] = new int[3];
    bottom[i][0] = arr[m - 1][i];
    bottom[i][1] = m - 1;
    bottom[i][2] = i;
  }
  for (int i = 0; i < m; i += 1) {
    left[i] = new int[3];
    left[i][0] = arr[i][0];
    left[i][1] = i;
    left[i][2] = 0;
  }
  for (int i = 0; i < m; i += 1) {
    right[i] = new int[3];
    right[i][0] = arr[i][n - 1];
    right[i][1] = i;
    right[i][2] = n - 1;
  }
  QuickSort(top, 0, n - 1);
  QuickSort(bottom, 0, n - 1);
  QuickSort(left, 0, m - 1);
  QuickSort(right, 0, m - 1);
  bool flag = false;
  int* result = new int[n * m / 2];
  int result_size = 0;
  while (true) {
    int i = 1;
    while (i < n and top[i][0]) {
      if (top[i - 1][0] == top[i][0]) {
        int value = top[i][0];
        result[result_size] = value;
        result_size += 1;
        ReplaceTopElement(arr, top, m, n, i);
        if (top[i][0] != value) {
          i -= 1;
        }
        ReplaceTopElement(arr, top, m, n, i);
        ReplaceBottom(arr, bottom, n, value);
        ReplaceLeft(arr, left, m, n, value);
        ReplaceRight(arr, right, m, value);
        flag = true;
        break;
      }
      i += 1;
    }
    i = 1;
    while (i < n and bottom[i][0]) {
      if (bottom[i - 1][0] == bottom[i][0]) {
        int value = bottom[i][0];
        result[result_size] = value;
        result_size += 1;
        ReplaceBottomElement(arr, bottom, n, i);
        if (bottom[i][0] != value) {
          i -= 1;
        }
        ReplaceBottomElement(arr, bottom, n, i);
        ReplaceTop(arr, top, m, n, value);
        ReplaceLeft(arr, left, m, n, value);
        ReplaceRight(arr, right, m, value);
        flag = true;
        break;
      }
      i += 1;
    }
    i = 1;
    while (i < m and left[i][0]) {
      if (left[i - 1][0] == left[i][0]) {
        int value = left[i][0];
        result[result_size] = value;
        result_size += 1;
        ReplaceLeftElement(arr, left, m, n, i);
        if (left[i][0] != value) {
          i -= 1;
        }
        ReplaceLeftElement(arr, left, m, n, i);
        ReplaceTop(arr, top, m, n, value);
        ReplaceBottom(arr, bottom, n, value);
        ReplaceRight(arr, right, m, value);
        flag = true;
        break;
      }
      i += 1;
    }
    i = 1;
    while (i < m and right[i][0]) {
      if (right[i - 1][0] == right[i][0]) {
        int value = right[i][0];
        result[result_size] = value;
        result_size += 1;
        ReplaceRightElement(arr, right, m, i);
        if (right[i][0] != value) {
          i -= 1;
        }
        ReplaceRightElement(arr, right, m, i);
        ReplaceTop(arr, top, m, n, value);
        ReplaceBottom(arr, bottom, n, value);
        ReplaceLeft(arr, left, m, n, value);
        flag = true;
        break;
      }
      i += 1;
    }
    if (not flag) {
      break;
    }
    flag = false;
  }
  std::cout << result_size << '\n';
  for (int i = 0; i < result_size; i += 1) {
    std::cout << result[i] << ' ';
  }
  delete[] result;
  for (int i = 0; i < n; i += 1) {
    delete[] top[i];
  }
  delete[] top;
  for (int i = 0; i < n; i += 1) {
    delete[] bottom[i];
  }
  delete[] bottom;
  for (int i = 0; i < m; i += 1) {
    delete[] left[i];
  }
  delete[] left;
  for (int i = 0; i < m; i += 1) {
    delete[] right[i];
  }
  delete[] right;
  for (int i = 0; i < m; i += 1) {
    delete[] arr[i];
  }
  delete[] arr;
}
