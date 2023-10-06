#include <cstring>
#include <iostream>

template <typename T> class SqList {
  int size;
  int cnt;
  T *_head;
  void realloc(const int inc = 1);

public:
  // 初始化链表
  SqList(int s);
  bool push_back(T elem);
  T pop_back();
  // 使用inline内联提高访问效率
  inline T get(int i) { return _head[i]; }
  inline int length() { return cnt; }
  inline bool empty() { return !cnt; }
  bool insert(T elem, int i);
  bool remove(int i);
  void traverse(void(T));
};

template <typename T> SqList<T>::SqList(int s) {
  _head = new T[s];
  size = s;
  cnt = 0;
}

/*函数功能：
如果空间不够重新申请空间*/
template <typename T> void SqList<T>::realloc(const int inc) {
  T *newarr = new T[cnt + inc];
  memcpy(newarr, _head, sizeof(T) * size);
  delete[] _head;
  _head = newarr;
  size += inc;
}

template <typename T> bool SqList<T>::push_back(T elem) {
  if (cnt == size)
    realloc(); // 重新申请空间
  _head[cnt] = elem;
  cnt++;
  return true;
}

template <typename T> T SqList<T>::pop_back() { return _head[--cnt]; }

template <typename T> bool SqList<T>::insert(T elem, int i) {
  if (i < 0 || i > cnt)
    return false;
  if (i == cnt - 1 || i == cnt)
    return push_back(elem);
  if (cnt == size)
    realloc();
  for (int j = cnt - 1; j >= i + 1; j--)
    _head[j] = _head[j - 1];
  _head[i] = elem;
  cnt++;
  return true;
}

template <typename T> bool SqList<T>::remove(int i) {
  if (i < 0 || i >= cnt)
    return false;
  for (int j = i + 1; j < cnt; j++)
    _head[j - 1] = _head[j];
  cnt--;
  return true;
}

template <typename T> void SqList<T>::traverse(void vis(T)) {
  for (int i = 0; i < cnt; i++)
    vis(_head[i]);
}

void print(int x) { std::cout << x << " "; }

int main() {
  SqList<int> M(100);
  M.push_back(1);
  M.push_back(2);
  M.push_back(3);
  M.traverse(print);
  std::cout << '\n';

  M.pop_back();
  M.traverse(print);
  std::cout << '\n';

  M.insert(99, 2);
  M.traverse(print);
  std::cout << '\n';

  M.remove(3);
  M.push_back(101);

  M.traverse(print);
  std::cout << '\n';

  M.remove(3);
  M.push_back(1919);
  M.traverse(print);
  std::cout << '\n';
  return 0;
}