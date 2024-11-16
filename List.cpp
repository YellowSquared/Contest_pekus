struct NodeList {
  int value;
  NodeList* p_next;
};

struct List {
  NodeList* head;
  NodeList* tail;
  size_t size;
};

/* Как работает список:

    голова      хвост  значение
      ||          ||    ||
      \/          \/    \/
List(0xafafaf, 0xaefaef, 3)============================
      ||                                              ||
      \/                                              \/
[&]=0xafafaf             [&]=0xeafeaf             [&]=0xaefaef
NodeList(0, 0xeafeaf) -> NodeList(1, 0xaefaef) -> NodeList(2, 0x0)
         /\   /\
значение ||   || указатель на следующий узел
*/

void Init(List& list) {
  list.head = list.tail = nullptr;
  list.size = 0;
}

void Free(List& list) {
  NodeList* cur = list.head;
  while (cur) {
    NodeList* next = cur->p_next;  // (*cur).p_next
    delete cur;
    cur = next;
  }
}

size_t Size(const List& list) {
  return list.size;
}

bool IsEmpty(const List& list) {
  return !Size(list);
}

int HeadValue(const List& list) {
  // assert list is not empty
  return list.head->value;
}

int TailValue(const List& list) {
  // assert list is not empty
  return list.tail->value;
}

void PushBack(List& list, int value) {
  NodeList* new_node = new NodeList;
  new_node->value = value;
  new_node->p_next = nullptr;
  ++list.size;
  if (list.tail) {
    list.tail->p_next = new_node;
    list.tail = new_node;
    return;
  }
  list.tail = list.head = new_node;
}

void PushFront(List& list, int value) {
  NodeList* new_node = new NodeList;
  (*new_node).value = value;
  ++list.size;
  if (list.head) {
    new_node->p_next = list.head;
    list.head = new_node;
    return;
  }
  list.head = list.tail = new_node;
}

void Push(List& list, size_t idx, int value) {
  if (idx == 0) {
    PushFront(list, value);
    return;
  }
  if (idx >= list.size) {
    PushBack(list, value);
    return;
  }
  ++list.size;
  NodeList* cur = list.head;
  while (--idx) {
    cur = cur->p_next;
  }
  /*
                      [&]=0xaafff=new_node
                      NodeList(2, 0x0)
                           ||
                           \/
  -> NodeList(0, 0xeafeaf) -> NodeList(1, 0xaefaef) ->
  */
  NodeList* new_node = new NodeList{value, cur->p_next};
  cur->p_next = new_node;
}

void PopFront(List& list) {
  --list.size;
  NodeList* p_next = list.head->p_next;
  delete list.head;
  list.head = p_next;  // Конечно из головы
  if (!list.head) {
    list.tail = nullptr;
  }
}

void PopBack(List& list) {
  Pop(list, list.size - 1);
}

/* Что происходит при удалении узла:

List(0xafafaf, 0xaefaef, 3)============================
      ||                                              ||
      \/                                              \/
[&]=0xafafaf             [&]=0xeafeaf             [&]=0xaefaef
NodeList(0, 0xeafeaf) -> NodeList(1, 0xaefaef) -> NodeList(2, 0x0)

|| || ||
\/ \/ \/

List(0xafafaf, 0xeafeaf, 3)=======
      ||                         ||
      \/                         \/
[&]=0xafafaf             [&]=0xeafeaf
NodeList(0, 0xeafeaf) -> NodeList(1, 0x0)
*/

void Pop(List& list, size_t idx) {
  if (!idx) {
    PopFront(list);
  }
  NodeList* cur = list.head;
  while (--idx) {
    cur = cur->p_next;
  }
  NodeList* to_delete = cur->p_next;
  cur->p_next = to_delete->p_next;
  delete to_delete;
  --list.size;
  if (!cur->p_next) {
    list.tail = cur;
  }
}
