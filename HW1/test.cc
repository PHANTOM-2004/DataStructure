#include <iostream>
#include <list>

std::list<int> p;
std::list<int>::iterator t;
int main() {
  p.push_back(1);
  p.push_back(2);
  p.push_back(3);
  p.push_back(4);
  p.push_back(5);
  t = p.begin();
  std::cout << *t << '\n';
  t++;
  std::cout << *t << '\n';
  t = p.erase(t);
  std::cout << *t << '\n';
  t++;
  std::cout << *t << '\n';
  int a;
  return 0;
}