#include <iostream>

template <typename T> class Deque {
  struct _node {
    T data;
    _node *next;
    _node *last;
  } *_head, *_rear;
  int _size;

public:
  Deque();
  void push_back(const T &elem);
  void pop_front();
  void push_front(const T &elem);
  void pop_back();
  inline T front() { return _head->next->data; }
  inline T back() { return _rear->data; }
  inline int size() { return _size; }
  inline bool empty() { return !_size; }
};

template <typename T> Deque<T>::Deque() {
  _head = new _node;
  _head->next = nullptr;
  _rear = _head;
  _size = 0;
}

template <typename T> void Deque<T>::push_back(const T &elem) {
  _node *p = new _node;
  p->data = elem;
  p->next = nullptr;
  p->last = _rear;
  _rear->next = p;
  _rear = p;
  _size++;
}

template <typename T> void Deque<T>::push_front(const T &elem) {
  if (empty()) {
    push_back(elem);
    return;
  }
  _node *p = new _node;
  p->data = elem;
  p->next = _head->next;
  p->last = _head;
  _head->next->last = p;
  _head->next = p;
  _size++;
}

template <typename T> void Deque<T>::pop_front() {
  _node *p = _head->next;
  _head->next = p->next;
  if (_rear == p) {
    _rear = _head;
  }
  delete p;
  _size--;
}

template <typename T> void Deque<T>::pop_back() {
  if (_size == 1) {
    pop_front();
    return;
  }

  _node *del = _rear;
  _rear->last->next = nullptr;
  _rear = _rear->last;
  delete del;
  _size--;
}

int main() {
  Deque<int> Q;
  Q.push_back(10);
  Q.push_back(1);
  // Q.push_back(2);
  // Q.push_back(3);
  std::cout << Q.front() << '\n';
  for (int i = 0; !Q.empty(); i++) {
    std::cout << Q.front() << '\n';
    Q.pop_front();
  }
  std::cout << Q.size();

  std::cout << "\n--------------\n";
  Q.push_front(10);
  Q.push_front(1);
  Q.push_front(2);
  Q.push_front(3);
  std::cout << Q.front() << '\n';
  for (int i = 0; !Q.empty(); i++) {
    std::cout << Q.front() << ' ' << Q.back() << '\n';
    Q.pop_back();
  }
  std::cout << Q.size();
  std::cout<<"__________________\n";
   for(int i=0;i<200;i++)
    Q.push_back(i);   
   for (int i = 0; !Q.empty(); i++) {
    std::cout << Q.back() << ' '<<Q.front()<<'\n';
    Q.pop_back();
  }

   std::cout << Q.size();
  std::cout<<"__________________\n";
   for(int i=0;i<200;i++)
    Q.push_front(i);   
   for (int i = 0; !Q.empty(); i++) {
    std::cout << Q.front() << ' '<<Q.back()<<'\n';
    Q.pop_front();
  }
}