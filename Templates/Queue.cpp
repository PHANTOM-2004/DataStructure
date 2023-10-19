#include <iostream>

template <typename T> class Queue {
  struct _node {
    T data;
    _node *next;
  } *_head, *_rear;
  int _size;

public:
  Queue();
  void push(const T &elem);
  void pop();
  inline T front() { return _head->next->data; };
  inline int size() { return _size; }
  inline bool empty() { return !_size; }
};

template <typename T> Queue<T>::Queue() {
  _head = new _node;
  _head->next = nullptr;
  _rear = _head;
  _size = 0;
}

template <typename T> void Queue<T>::push(const T &elem) {
  _node *p = new _node;
  p->data = elem;
  p->next = nullptr;
  _rear->next = p;
  _rear = p;
  _size++;
}

template <typename T> void Queue<T>::pop() {
  _node *p = _head->next;
  _head->next = p->next;
  if (_rear == p)
    _rear = _head;
  delete p;
  _size--;
}

int main() {
  Queue<int> Q;
  Q.push(10);
  Q.push(1);
  Q.push(2);
  Q.push(3);
  std::cout << Q.front() << '\n';
  for (int i = 0; !Q.empty(); i++) {
    std::cout << Q.front() << '\n';
    Q.pop();
  }
  std::cout << Q.size() << '\n';
  //
  Q.push(10);
  Q.push(1);
  Q.push(2);
  Q.push(3);
  std::cout << Q.front() << '\n';
  for (int i = 0; !Q.empty(); i++) {
    std::cout << Q.front() << '\n';
    Q.pop();
  }
  std::cout<<"-------------------------\n";

  for(int i=0;i<200;i++)
    Q.push(i);   
   for (int i = 0; !Q.empty(); i++) {
    std::cout << Q.front() << '\n';
    Q.pop();
  }
}