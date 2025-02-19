#include <iostream>

int game(int n, int turn) {
  if (n < 0) {
    return ((turn % 2) + 1000);
  }
  if (n % 3 == 0) {
    return game(n - 1, turn + 1) or game(n - 2, turn + 1);
  } else if (n % 3 == 1) {
    return game(n - 1, turn + 1) or game(n - 3, turn + 1);
  } else if (n % 3 == 2) {
    return game(n - 1, turn + 1) or game(n - 2, turn + 1) or game(n - 3, turn + 1);
  } else {
    return turn % 2;
  }

}

int main() {
  int n = 0;
  std::cin >> n;
  std::cout << game(n, 0);
}
