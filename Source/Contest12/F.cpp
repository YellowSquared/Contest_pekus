#include <iostream>

int Min(int a, int b) {
  return (a < b) ? a : b;
}

int TicketsBuying(int clients, int* one_ticket, int* two_tickets, int* three_tickets) {
  if (clients == 1) {
    return one_ticket[0];
  }
  if (clients == 2) {
    return Min(one_ticket[0] + one_ticket[1], two_tickets[0]);
  }
  if (clients == 3) {
    return Min(Min(one_ticket[0] + two_tickets[1], three_tickets[0]),
               Min(two_tickets[0] + one_ticket[2], one_ticket[0] + one_ticket[1] + one_ticket[2]));
  }

  /*
  Допустим, у нас 4 человека в очереди. Тогда, у нас в качестве ответа могут быть следующие варианты:
  - каждый покупает билет
  - 1 покупает на себя и второго | -> остальные покупают на себя
                                 | -> 3-ий покупает на себя и 4-ого
                                 
  - 3 покупает на себя, 2 и 3    | -> 4-ый покупает на себя
  Для каждого следующего человека в очереди у нас есть выбор из 3-ёх предыдущих вариантов. Мы должны выбрать минимально возможный.
  Также, поскольку мы ссылаемся только на ответы для n - 1, n - 2 и n - 3 людей в очереди, то мы можем хранить ответы только для них, 
  а не для всех от 1 до n.
  */

  int dynamic[4];
  int a = 0;
  int b = 0;
  int c = 0;
  dynamic[0] = one_ticket[0];
  dynamic[1] = Min(one_ticket[0] + one_ticket[1], two_tickets[0]);
  dynamic[2] = Min(Min(one_ticket[0] + two_tickets[1], three_tickets[0]),
                   Min(two_tickets[0] + one_ticket[2], one_ticket[0] + one_ticket[1] + one_ticket[2]));

  for (int i = 3; i < clients; ++i) {
    a = dynamic[2] + one_ticket[i];
    b = dynamic[1] + two_tickets[i - 1];
    c = dynamic[0] + three_tickets[i - 2];
    dynamic[3] = Min(Min(a, b), Min(b, c));
    dynamic[0] = dynamic[1];
    dynamic[1] = dynamic[2];
    dynamic[2] = dynamic[3];
  }

  return dynamic[2];
}

int main() {
  int clients = 0;
  std::cin >> clients;
  int* one_ticket = new int[clients];
  int* two_tickets = new int[clients];
  int* three_tickets = new int[clients];
  for (int i = 0; i < clients; ++i) {
    std::cin >> one_ticket[i] >> two_tickets[i] >> three_tickets[i];
  }
  std::cout << TicketsBuying(clients, one_ticket, two_tickets, three_tickets);
  delete[] one_ticket;
  delete[] two_tickets;
  delete[] three_tickets;
  return 0;
}
