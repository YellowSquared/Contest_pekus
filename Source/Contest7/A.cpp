#include <iostream>
int main() {
  int n1 = 0;
  int n2 = 0;
  int n3 = 0;
  int n4 = 0;

  int* caps = new int[100000];
  int* shirts = new int[100000];
  int* t_shirts = new int[100000];
  int* boots = new int[100000];

  std::cin >> n1;

  for (int i = 0; i < n1; i++) {
    int tmp = 0;
    std::cin >> tmp;
    caps[tmp]++;
  }

  std::cin >> n2;

  for (int i = 0; i < n2; i++) {
    int tmp = 0;
    std::cin >> tmp;
    shirts[tmp]++;
  }

  std::cin >> n3;

  for (int i = 0; i < n3; i++) {
    int tmp = 0;
    std::cin >> tmp;
    t_shirts[tmp]++;
  }

  std::cin >> n4;

  for (int i = 0; i < n4; i++) {
    int tmp = 0;
    std::cin >> tmp;
    boots[tmp]++;
  }

  int min_caps = 1000001;
  int min_shirts = 1000001;
  int min_t_shirts = 1000001;
  int min_boots = 1000001;

  for (int i = 0; i < 100000; i++) {
    if (caps[i] > 0 && shirts[i] > 0 && t_shirts[i] > 0 && boots[i] > 0) {
      std::cout << i << " " << i << " " << i << " "
                << i;
    }
  }

  delete[] caps, shirts, t_shirts, boots;
}