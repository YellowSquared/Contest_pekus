// 
// Здесь представленна реализация стека через список. Если нужно - то функции легко исправляются
// Найти функции можно в файле List.cpp
//
// Основное отличие List и Stack - методы работы с ними
// Stack (стек) - что первое пришло, то выходит последним.
//
// Пример: Коробка с книгами, из которой вы не можете взять книги, 
// которые лежат ниже, пока не достанете верхние книги.
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

struct Stack {
  List list;
};

int Top(const Stack& stack) {
  return HeadValue(stack.list);
}

void Push(Stack& stack, int value) {
  PushFront(stack.list, value);
}

void Pop(Stack& stack) {
  PopFront(stack.list);
}

size_t Size(const Stack& stack) {
  return Size(stack.list);
}

bool IsEmpty(const Stack& stack) {
  return IsEmpty(stack.list);
}

void Init(Stack& stack) {
  Init(stack.list);
}

void Free(Stack& stack) {
  Free(stack.list);
}
