// Paste your code here
// NOTE: If you use java, your Main class must be named solution

#include <iostream>

const int MAXN = 2100;
int a[MAXN];
int b[MAXN];
int ansadd[MAXN * 2];
int ansmul[MAXN * 2];
int n, m;
int nl, ml;
void add() {
  int max = std::max(ml, nl);
  for (int i = 0; i <= max; i++) {
    ansadd[i] = a[i] + b[i];
  }
  for (int i = 0; i <= max; i++) {
    if (ansadd[i])
      std::cout << ansadd[i] << " " << i << " ";
  }
  std::cout << '\n';
}

void mul() {
  int maxl = ml + nl;
  for (int i = 0; i <= maxl; i++) {
    for (int j = 0; j <= i; j++) {
      ansmul[i] += a[j] * b[i - j];
    }
  }
  for (int i = 0; i <= maxl; i++) {
    if (ansmul[i])
      std::cout << ansmul[i] << " " << i << " ";
  }
  std::cout << '\n';
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int at, xp;
    std::cin >> at >> xp;
    a[xp] = at;
    ml = std::max(ml, xp);
  }
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int bt, xp;
    std::cin >> bt >> xp;
    b[xp] = bt;
    nl = std::max(nl, xp);
  }
  int opt = 0;
  std::cin >> opt;
  if (opt == 0)
    add();
  else if (opt == 1)
    mul();
  else
    add(), mul();
}