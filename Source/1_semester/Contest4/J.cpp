#include <iostream>

void Swapl(int64_t &lhs, int64_t &rhs) {
  int64_t tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

void InverseBubbleSort(int64_t *arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    bool were_permutations = false;

    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        Swapl(arr[j], arr[j + 1]);
        were_permutations = true;
      }
    }

    if (!were_permutations) {
      return;
    }
  }
}

int main() {
  int n = 0;
  int k = 0;

  std::cin >> n >> k;

  auto **arr = new int64_t *[n];

  for (int i = 0; i < n; i++) {
    arr[i] = new int64_t[k];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      std::cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    InverseBubbleSort(arr[i], k);
  }

  for (int i = 0; i < n; i++) {
    bool result = true;
    int64_t avaliable = arr[i][0];

    for (int j = 1; j < k; j++) {
      avaliable -= arr[i][j];
      if (avaliable < 0) {
        result = false;
        break;
      }
    }

    if (result) {
      std::cout << "yes"
                << "\n";
    } else {
      std::cout << "no"
                << "\n";
    }
  }

  for (int i = 0; i < n; i++) {
    delete[] arr[i];
  }

  delete[] arr;
}