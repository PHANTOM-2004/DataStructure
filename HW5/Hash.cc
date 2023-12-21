#include <cmath>
#include <iostream>
#include <vector>
using ull = unsigned long long;

class Hash {
  int BASE;
  int n;
  int table_size;
  std::vector<int> table;

  bool is_prime(const ull number) {
    if (number == 1)
      return false;
    for (ull i = 2, l = (ull)std::sqrt(number); i <= l; i++) {
      if (number % i == 0)
        return false;
    }
    return true;
  }

  int hash(const std::string &s) const {
    ull res = 0;
    for (auto iter : s) {
      res = res * BASE + iter;
    }
    return res % table_size;
  }

  void construct_table() {
    int p;
    std::cin >> n >> p;
    if (is_prime(p))
      table_size = p;
    else {
      while (is_prime(++p) == false)
        ;
      table_size = p;
    }
    table.resize(table_size, 0);
  }
  inline int Square(const int t) { return t * t; }

  int insert(const std::string &s) {
    int h = hash(s) % table_size;

    if (table[h] == 0) {
      table[h] = 1;
      return h;
    } else {
      ull t = 0;
      for (int i = 0; i <= table_size; i++) {
        // refer to p111_data.cpp
        t = ((h + Square((i + 1) / 2 % table_size) * (i % 2 ? 1 : -1)) %
                 table_size +
             table_size) %
            table_size;
        // t = h + i * i % table_size;
        // t %= table_size;

        if (table[t] == 0) {
          table[t] = 1;
          return t;
        }
      }
    }
    return -1;
  }

public:
  Hash() { BASE = 37; }

  void solve() {
    construct_table();
    std::string s;
    for (int i = 0; i < n; i++) {
      std::cin >> s;
      int pos = insert(s);
      if (pos == -1)
        std::cout << '-';
      else
        std::cout << pos;
      std::cout << " \n"[i == n - 1];
    }
  }
};

Hash Solution;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input4.txt", "r", stdin);
  Solution.solve();
  return 0;
}