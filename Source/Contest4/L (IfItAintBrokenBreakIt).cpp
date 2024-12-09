#include <iostream>
#include <cmath>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  int* arr = new int[n];
  int position = 0;
  int* positive_numbers = new int[n]{};
  int* negative_numbers = new int[n]{};
  int i2 = 0;
  for (int i = 0; i < n; i += 1) {
    std::cin >> arr[i];
    position += arr[i];
    if (arr[i] > 0) {
      positive_numbers[i2] = arr[i];
      i2 += 1;
    } else {
      negative_numbers[i - i2] = arr[i];
    }
  }
  int p_positive = 1;
  int p2_positive = 1;
  int number_positive = positive_numbers[0];
  int* max_numbers_north = new int[k]{};
  int new_beginning_positive = 1;
  int max_numbers_north_index = 0;
  int k2 = k;
  while (k > 0) {
    while (positive_numbers[p2_positive]) {
      if (positive_numbers[p2_positive] > number_positive) {
        int temp = positive_numbers[p_positive];
        positive_numbers[p_positive] = positive_numbers[p2_positive];
        positive_numbers[p2_positive] = temp;
        p_positive += 1;
      }
      p2_positive += 1;
    }
    if (p_positive - new_beginning_positive + 1 <= k + 1) {
      int j = new_beginning_positive - 1;
      if (p_positive - new_beginning_positive + 1 == k + 1) {
        j = new_beginning_positive;
      }
      for (; j < p_positive; j += 1) {
        max_numbers_north[max_numbers_north_index] = positive_numbers[j];
        max_numbers_north_index += 1;
      }
      k -= p_positive - new_beginning_positive + 1;
      p_positive += 1;
      p2_positive = p_positive;
      number_positive = positive_numbers[p_positive - 1];
      new_beginning_positive = p_positive;
    } else {
      int j = p_positive;
      while (positive_numbers[j] != 0) {
        positive_numbers[j] = 0;
        j += 1;
      }
      new_beginning_positive += 1;
      p_positive = new_beginning_positive;
      p2_positive = p_positive;
      number_positive = positive_numbers[p_positive - 1];
    }
  }
  k = k2;
  int p_negative = 1;
  int p2_negative = 1;
  int number_negative = negative_numbers[0];
  int* max_numbers_south = new int[k]{};
  int new_beginning_negative = 1;
  int max_numbers_south_index = 0;
  while (k > 0) {
    while (negative_numbers[p2_negative]) {
      if (negative_numbers[p2_negative] < number_negative) {
        int temp = negative_numbers[p_negative];
        negative_numbers[p_negative] = negative_numbers[p2_negative];
        negative_numbers[p2_negative] = temp;
        p_negative += 1;
      }
      p2_negative += 1;
    }
    if (p_negative - new_beginning_negative + 1 <= k + 1) {
      int j = new_beginning_negative - 1;
      if (p_negative - new_beginning_negative + 1 == k + 1) {
        j = new_beginning_negative;
      }
      for (; j < p_negative; j += 1) {
        max_numbers_south[max_numbers_south_index] = negative_numbers[j];
        max_numbers_south_index += 1;
      }
      k -= p_negative - new_beginning_negative + 1;
      p_negative += 1;
      p2_negative = p_negative;
      number_negative = negative_numbers[p_negative - 1];
      new_beginning_negative = p_negative;
    } else {
      int j = p_negative;
      while (negative_numbers[j] != 0) {
        negative_numbers[j] = 0;
        j += 1;
      }
      new_beginning_negative += 1;
      p_negative = new_beginning_negative;
      p2_negative = p_negative;
      number_negative = negative_numbers[p_negative - 1];
    }
  }
  k = k2;
  int max_error_north = 0;
  for (int i = 0; i < k; i += 1) {
    max_error_north += max_numbers_south[i];
  }
  int abs_new_position1 = 0;
  if (position - max_error_north * 2 > 0) {
    abs_new_position1 = position - max_error_north * 2;
  } else {
    abs_new_position1 = max_error_north * 2 - position;
  }
  int max_error_south = 0;
  for (int i = 0; i < k; i += 1) {
    max_error_south += max_numbers_north[i];
  }
  int abs_new_position2 = 0;
  if (position - max_error_south * 2 > 0) {
    abs_new_position2 = position - max_error_south * 2;
  } else {
    abs_new_position2 = max_error_south * 2 - position;
  }
  if (abs_new_position1 >= abs_new_position2) {
    std::cout << abs_new_position1;
  } else {
    std::cout << abs_new_position2;
  }
  delete[] arr;
  delete[] positive_numbers;
  delete[] negative_numbers;
  delete[] max_numbers_north;
  delete[] max_numbers_south;
  return 0;
}
