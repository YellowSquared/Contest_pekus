// 
// Здесь представленна реализация очереди через список. Если нужно - то функции легко исправляются
// Найти функции можно в файле List.cpp
//
// Основное отличие List и Queue - методы работы с ними
// Queue (очередь) - что первое пришло, то первым и выходит.
//

struct NodeList {
  int value;
  NodeList* p_next;
};

struct List {
  NodeList* head;
  NodeList* tail;
  size_t size;
};

struct Queue {
  List list;
};

int Head(const Queue& queue) {
  return HeadValue(queue.list);
}

int Tail(const Queue& queue) {
  return TailValue(queue.list);
  // queue.list.tail -> value;
}

void Push(Queue& queue, int value) {
  PushBack(queue.list, value);
}

void Pop(Queue& queue) {
  PopFront(queue.list);
}

size_t Size(Queue& queue) {
  return Size(queue.list);
}

bool IsEmpty(Queue& queue) {
  return IsEmpty(queue.list);
}

void Init(Queue& queue) {
  Init(queue.list);
}

void Free(Queue& queue) {
  Free(queue.list);
}
