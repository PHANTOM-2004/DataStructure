/**
 * p77 随机测试数据生成程序
 * @author 张校
 * @date 2021-10-25
 * @brief 使用方法：直接编译运�?
 */
#include <fstream>
#include <iostream>

using namespace std;

struct Node {
  Node *next;
  int p, e;
  Node() { next = NULL; }
  Node(int p_, int e_, Node *n_ = NULL) : p(p_), e(e_), next(n_) {}
  ~Node() {
    if (next != NULL)
      delete next;
  }
};

class List {
private:
  Node head;

public:
  List() { head.next = NULL; }
  ~List() { clear(); }
  void clear() {
    if (head.next != NULL)
      delete head.next;
    head.next = NULL;
  }
  void push(int p, int e,
            bool rev = false) // 维护一个有序链�?
  {
    if (head.next == NULL) // 队列为空，直接插入链表头
    {
      head.next = new Node(p, e, NULL);
      return;
    } else {
      Node *i = &head;
      while (i->next != NULL &&
             (!rev && i->next->e <= e || rev && i->next->e >= e))
        i = i->next;

      if (i->e == e) // 多项式中存在指数相同�?
        i->p += p;
      else
        i->next = new Node(p, e, i->next);
    }
  }

  void merge(const List &l) {
    Node *p1 = &head, *p2 = l.head.next;
    while (p1->next != NULL && p2 != NULL) {
      if (p2->e == p1->next->e) {
        p1->next->p += p2->p;
        p1 = p1->next;
        p2 = p2->next;
      } else if (p2->e > p1->next->e)
        p1 = p1->next;
      else {
        p1->next = new Node(p2->p, p2->e, p1->next);
        p1 = p1->next;
        p2 = p2->next;
      }
    }

    if (p1->next == NULL) {
      while (p2 != NULL) {
        p1->next = new Node(p2->p, p2->e, NULL);
        p1 = p1->next;
        p2 = p2->next;
      }
    }
  }

  void revert() {
    Node *p = head.next;
    head.next = NULL;
    while (p != NULL) {
      Node *t = head.next;
      head.next = p;
      p = p->next;
      head.next->next = t;
    }
  }

  void show(ofstream &f) {
    for (Node *p = head.next; p != NULL; p = p->next)
      if (p->p != 0)
        f << p->p << ' ' << p->e << ' ';
    f << endl;
  }
  // 这里注意一下，如果class中含有指针，这样传参时一定要用引用，或者直接传地址
  // 因为如果直接传clas，这个参数在函数结束时会调用析构函数，在析构函数中会把原来的内存也销毁了！！�?
  // 在这里，因为参数l1和main函数中申明的l1中head.next是一样的！！�?
  static void add(const List &l1, const List &l2,
                  List &l3) // 相加，分别加�?
  {
    l3.merge(l1);
    l3.merge(l2);
  }

  static void mul(const List &l1, const List &l2,
                  List &l4) // 相乘，双重for循环
  {
    List lt;
    for (Node *i = l1.head.next; i != NULL; i = i->next) {
      lt.clear();
      for (Node *j = l2.head.next; j != NULL; j = j->next)
        lt.push(i->p * j->p, i->e + j->e, true); // 系数相乘，指数相�?
      lt.revert();
      l4.merge(lt);
    }
  }
};

int main() {
  int n, m, ope;
  List l1, l2, l3, l4;
  char file_input[25], file_output[25];
  int test_num = 15; // 测试数据个数
  srand((unsigned int)time(NULL));
  for (int i = 1; i <= test_num; i++) {
    sprintf(file_input, "input%d.txt", i);
    sprintf(file_output, "output%d.txt", i);
    ofstream fin(file_input), fout(file_output);

    if (i <= test_num * 0.15) {
      n = (rand() % 5) + 7;
      m = (rand() % 5) + 7;
      ope = 0;
    } else if (i <= test_num * 0.34) {
      n = (rand() % 10) + 30;
      m = (rand() % 10) + 30;
      ope = 1;
    } else if (i <= test_num * 0.67) {
      n = (rand() % 10) + 80;
      m = (rand() % 10) + 80;
      ope = 2;
    } else {
      n = (rand() % 50) + 1975;
      m = (rand() % 50) + 1975;
      ope = 2;
    }

    l1.clear();
    l2.clear();
    l3.clear();
    l4.clear();

    for (int j = 0; j < n; j++) {
      int p = i > test_num * 0.67 ? ((rand() % n) + n) * (1 - (rand() % 2) * 2)
                                  : rand() % n + 1;
      int e = j;
      l1.push(p, e);
    }
    for (int j = 0; j < m; j++) {
      int p = i > test_num * 0.67 ? ((rand() % m) + m) * (1 - (rand() % 2) * 2)
                                  : rand() % m + 1;
      int e = j;
      l2.push(p, e);
    }
    fin << n << endl;
    l1.show(fin);
    fin << m << endl;
    l2.show(fin);
    fin << ope << endl;
    if (ope % 2 == 0) {
      List::add(l1, l2, l3);
      l3.show(fout);
    } // 相加
    if (ope >= 1) {
      List::mul(l1, l2, l4);
      l4.show(fout);
    } // 相乘

    fin.close();
    fout.close();
  }
  return 0;
}