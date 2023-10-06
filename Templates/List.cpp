#include <iostream>

template <typename T> class List {
  struct _Node {
    T _data;
    _Node *next;
  } *_head, *_last;
  int size;

public:
  List();
  inline int length() { return size; }
  inline bool empty() { return size == 0; }
  bool push_front(T elem);
  bool push_back(T elem);
  T pop_front();
  bool get(int i, T &elem);
  bool insert(int i, T elem);
  void traverse(void visit(T));
  bool remove(int i);
};

template <typename T> List<T>::List() {
  _head = new _Node;
  _head->next = nullptr;
  _last = nullptr;
  size = 0;
}

template <typename T> bool List<T>::push_front(T elem) {
  _Node *newnode = new _Node;
  newnode->next = _head->next;
  newnode->_data = elem;
  _head->next = newnode;
  if (!length())
    _last = newnode;
  size++;
  return true;
}

template <typename T> bool List<T>::push_back(T elem) {
  if (!length()) {
    push_front(elem);
    return true;
  }
  _last->next = new _Node;
  _last->next->_data = elem;
  _last->next->next = nullptr;
  _last = _last->next;
  size++;
  return true;
}

template <typename T> T List<T>::pop_front() {
  _Node *del = _head->next;
  T data = del->_data;
  _head->next = del->next;
  delete del;
  size--;
  if (size == 0)
    _last = nullptr;
  return data;
}

template <typename T> bool List<T>::get(int i, T &elem) {
  if (i >= size || i < 0)
    return false;
  int j = 0;
  _Node *p;
  for (p = _head; j <= i; p = p->next, j++)
    ;
  elem = p->_data;
  return true;
}

template <typename T> bool List<T>::insert(int i, T elem) {
  if (i > size || i < 0)
    return false;
  else if (i == 0)
    push_front(elem);
  else if (i == size)
    push_back(elem);
  else {
    int j = 0;
    _Node *newnode = new _Node, *p;
    for (p = _head; j <= i - 1; p = p->next, j++)
      ;
    newnode->next = p->next;
    newnode->_data = elem;
    p->next = newnode;
    size++;
  }
  return true;
}

template <typename T> void List<T>::traverse(void visit(T)) {
  for (_Node *p = _head->next; p != nullptr; p = p->next)
    visit(p->_data);
}

template <typename T> bool List<T>::remove(int i) {
  if (i >= size || i < 0)
    return false;
  int j = 0;
  _Node *p;
  for (p = _head; j <= i - 1; p = p->next, j++)
    ;
  T delnode = p->next;
  p->next = p->next->next;
  delete delnode;
  return true;
}
void output(int t) { std::cout << t << '\n'; }

int main() {
  List<int> L;
  int elem = -1;
  L.push_front(0);
  L.push_back(1);
  L.push_back(2);
  L.push_front(3);
  L.insert(2, 99);
  L.get(2, elem);
  std::cout << elem << '\n';
  std::cout << "-------------\n";
  L.traverse(output);
  std::cout << "-------------\n";
  std::cout << L.pop_front() << '\n';
  std::cout << "-------------\n";
  L.traverse(output);
  return 0;
}