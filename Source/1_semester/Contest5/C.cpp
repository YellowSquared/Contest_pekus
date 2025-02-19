#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;

  int m = 0;
  std::cin >> m;

  int** dist = new int*[n];
  int** result = new int*[n];
  
  for (int i = 0; i < n; i++) {
    dist[i] = new int[m];
    result[i] = new int[m];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dist[i][j] = i + j;
    }
  }

  int val = 0;
  for (int k = 0; k < n + m - 2; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dist[i][j] == k) {
          result[i][j] = val;
          val++;
        }
      }
    }
  }
  result[n - 1][m - 1] = n * m - 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << result[i][j] << " ";
    }
    if (i != n - 1) {
      std::cout << "\n";
    }
  }

  for (int i = 0; i < n; i++) {
    delete[] dist[i];
    delete[] result[i];
  }

  delete[] dist;
  delete[] result;
}