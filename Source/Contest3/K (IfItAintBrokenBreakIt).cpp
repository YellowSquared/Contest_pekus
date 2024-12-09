#include <iostream>
#include <cmath>

int main() {
  int w = 0;
  int h = 0;
  int n = 0;
  std::cin >> w >> h >> n;
  u_int64_t left = ceil(sqrt(w) * sqrt(h) * sqrt(n));
  if (left % w != 0 and left % h != 0) {
    if ((left / w + 1) * w > (left / h + 1) * h) {
      left = (left / h + 1) * h;
    } else {
      left = (left / w + 1) * w;
    }
  }
  u_int64_t right = ceil(sqrt(n));
  if (w >= h) {
    right *= w;
  } else {
    right *= h;
  }
  u_int64_t i = left;
  u_int64_t j = left;
  if (left % w != 0) {
    i = (left / w + 1) * w;
  }
  if (left % h != 0) {
    j = (left / h + 1) * h;
  }
  auto* possible_answers = new u_int64_t[right - left + 1];
  u_int64_t k = 0;
  while (i <= right or j <= right) {
    if (i == j) {
      possible_answers[k] = i;
      i += w;
      j += h;
    } else if (i > j) {
      possible_answers[k] = j;
      j += h;
    } else {
      possible_answers[k] = i;
      i += w;
    }
    k += 1;
  }
  left = 0;
  right = k - 1;
  u_int64_t possible_answer = 0;
  while (right >= left) {
    u_int64_t mid_index = (right + left) / 2;
    u_int64_t mid = possible_answers[mid_index];
    if (mid % w == 0) {
      u_int64_t q = 0;
      if (n % (mid / w) == 0) {
        q = n / (mid / w) * h;
      } else {
        q = (n / (mid / w) + 1) * h;
      }
      if (q <= mid) {
        if (mid < possible_answer or possible_answer == 0) {
          possible_answer = mid;
        }
        right = mid_index;
      } else {
        if (left != mid_index) {
          left = mid_index;
        } else {
          left += 1;
        }
      }
    } else {
      u_int64_t q = 0;
      if (n % (mid / h) == 0) {
        q = n / (mid / h) * w;
      } else {
        q = (n / (mid / h) + 1) * w;
      }
      if (q <= mid) {
        if (mid < possible_answer or possible_answer == 0) {
          possible_answer = mid;
        }
        right = mid_index;
      } else {
        if (left != mid_index) {
          left = mid_index;
        } else {
          left += 1;
        }
      }
    }
    if (left == right) {
      break;
    }
  }
  std::cout << possible_answer;
  delete[] possible_answers;
  return 0;
}
