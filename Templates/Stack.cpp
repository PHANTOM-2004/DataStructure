#include <iostream>

const int STACK_SIZE = 100;
template <typename T>
class Stack
{
  T *_base;
  T *_top;
  int _size;

public:
  Stack(const int &size = STACK_SIZE);
  inline int size() { return _top - _base; }
  inline bool empty() { return _top == _base; }
  inline void push(const T &elem);
  inline T pop() { return *--_top; }
  inline T top() { return _top[-1]; }
};

template <typename T>
Stack<T>::Stack(const int &size)
{
  _base = new T[size];
  _top = _base;
  _size = size;
}

template <typename T>
void Stack<T>::push(const T &elem)
{
  if (_top - _base == _size)
  {
    T *newmem = new T[_size << 1];
    memcpy(newmem, _base, _size * sizeof(T));
    delete[] _base;
    _base = newmem;
    _top = _base + _size;
    _size *= 2;
  }
  *_top++ = elem;
}

int main()
{
  Stack<int> S(4);
  for (int i = 0; i < 10; i++)
    S.push(i);
  for (int i = 0; !S.empty(); i++)
  {
    std::cout << S.pop() << " ";
  }
  return 0;
}