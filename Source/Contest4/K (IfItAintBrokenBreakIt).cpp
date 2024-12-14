#include <iostream>
#include <cmath>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int* begins = new int[n];
  int* ends = new int[n];
  int temp_arr[2];
  for (int i = 0; i < n; i += 1) {
    std::cin >> temp_arr[0];
    std::cin >> temp_arr[1];
    if (temp_arr[0] > temp_arr[1]) {
      begins[i] = temp_arr[1];
      ends[i] = temp_arr[0];
    } else {
      begins[i] = temp_arr[0];
      ends[i] = temp_arr[1];
    }
    int j = i;
    while (j > 0 and begins[j] < begins[j - 1]) {
      int q = begins[j];
      begins[j] = begins[j - 1];
      begins[j - 1] = q;
      j -= 1;
    }
    j = i;
    while (j > 0 and ends[j] < ends[j - 1]) {
      int q = ends[j];
      ends[j] = ends[j - 1];
      ends[j - 1] = q;
      j -= 1;
    }
  }
  int point = 0;
  int* answers = new int[m];
  for (int i = 0; i < m; i += 1) {
    std::cin >> point;
    int amount_of_begins_before_the_point = -1;
    int amount_of_ends_before_the_point = -1;
    int left = 0;
    int right = n - 1;
    while (right > left + 1) {
      int mid = (right + left) / 2;
      if (begins[mid] > point) {
        right = mid;
      } else {
        left = mid;
      }
    }
    if (point >= begins[n - 1]) {
      amount_of_begins_before_the_point = n;
    } else if (point < begins[0]) {
      amount_of_begins_before_the_point = 0;
    } else {
      amount_of_begins_before_the_point = right;
    }
    left = 0;
    right = n;
    while (right > left + 1) {
      int mid = (right + left) / 2;
      if (ends[mid] >= point) {
        right = mid;
      } else {
        left = mid;
      }
    }
    if (point > ends[n - 1]) {
      amount_of_ends_before_the_point = n;
    } else if (point <= ends[0]) {
      amount_of_ends_before_the_point = 0;
    } else {
      amount_of_ends_before_the_point = right;
    }
    answers[i] = amount_of_begins_before_the_point - amount_of_ends_before_the_point;
  }
  for (int i = 0; i < m; i += 1) {
    std::cout << answers[i] << " ";
  }
  delete[] begins;
  delete[] ends;
  delete[] answers;
  return 0;
}
