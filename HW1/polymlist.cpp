#include <iostream>
#include <list>

struct node {
  int val;
  int expn;
};

std::list<node> A, B;
std::list<node>::iterator ita, itb;
std::list<node> mul_ans;

void output(std::list<node> &Ans) {
  for (auto iter : Ans) {
    std::cout << iter.val << " " << iter.expn << " ";
  }
}

void add(std::list<node> &A1, std::list<node> &B1) {
  std::list<node> Ans;
  ita = A1.begin();
  itb = B1.begin();
  while (ita != A1.end() && itb != B1.end()) {
    if (ita->expn < itb->expn) {
      ita++;
    } else if (ita->expn > itb->expn) {
      A1.insert(ita, *itb);
      itb++;
    } else {
      ita->val += itb->val;
      if (ita->val == 0) {
        ita = A1.erase(ita);
      } else {
        ita++;
      }
      itb++;
    }
  }
  while (itb != B1.end())
    A1.push_back(*itb++);
}

void mul(std::list<node> &A1, std::list<node> &B1, std::list<node> &Ans) {
  std::list<node> tmp;
  for (auto &itera : A1) {
    tmp.clear();
    for (auto &iterb : B1) {
      node now = (node){itera.val * iterb.val, itera.expn + iterb.expn};
      tmp.push_back(now);
    }
    add(Ans, tmp);
  }
}

int m, n;
int main() {

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input12.txt", "r", stdin);
  freopen("output12.out", "w", stdout);
#endif
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int at, xp;
    std::cin >> at >> xp;
    A.push_back((node){at, xp});
  }
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int bt, xp;
    std::cin >> bt >> xp;
    B.push_back((node){bt, xp});
  }
  int opt = 0;
  std::cin >> opt;
  if (opt == 0) {
    add(A, B);
    output(A);
  } else if (opt == 1) {
    mul(A, B, mul_ans);
    output(mul_ans);
  } else {
    std::list<node> tmp;
    tmp.assign(A.begin(), A.end());
    add(A, B);

    output(A);
    std::cout << '\n';
    mul(tmp, B, mul_ans);
    output(mul_ans);
  }
  std::cout << '\n';

  return 0;
}