#include <cstring>
#include <iostream>
#include <vector>
// 58013091638256722670150
struct Biginteger {
  int length;
  std::vector<int> num;
  Biginteger(long long x = 0) {
    num.resize(0);
    num.push_back(x > 0 ? 0 : 1);
    for (length = 1; x; length++) {
      num.push_back(x % 10);
      x /= 10;
    }
    length--;
  }

  int &operator[](int i) { return num[i]; }
  void print() {
    for (int j = std::max(length, 1); j >= 1; j--) {
      std::cout << num[j];
    }
  }

  void flatten(int L) {
    num.resize(L + 5, 0);
    for (int i = 1; i <= L; i++) {
      num[i + 1] = num[i + 1] + num[i] / 10;
      num[i] = num[i] % 10;
    }
    length = num.size() - 1;
    for (; !num[length];)
      length--;
    num.resize(length + 5, 0);
  }
};

Biginteger operator+(Biginteger a, Biginteger b) {
  Biginteger c;
  int len = std::max(a.length, b.length);
  c.num.resize(len + 5, 0);
  for (int i = 1; i <= len; i++)
    c[i] += (i <= a.length ? a[i] : 0) + (i <= b.length ? b[i] : 0);
  c.flatten(len + 1);
  return c;
}

Biginteger operator*(Biginteger a, int b) {
  Biginteger c;
  int len = a.length;
  c.num.resize(len + 5, 0);
  for (int i = 1; i <= len; i++)
    c[i] = a[i] * b;
  c.flatten(len + 12);
  return c;
}

Biginteger operator*(Biginteger a, Biginteger b) {
  int len = a.length + b.length + 1;
  Biginteger c;
  c.num.resize(len);
  for (int i = 1; i <= a.length; i++) {
    for (int j = 1; j <= b.length; j++) {
      c[i + j - 1] += a[i] * b[j];
    }
  }
  c.flatten(len);
  return c;
}

Biginteger operator/(Biginteger a, int b) {
  Biginteger c;
  c.num.resize(a.length);
  int x = 0;
  for (int i = a.length; i >= 1; i--) {
    c[i] = (10 * x + a[i]) / b;
    x = (10 * x + a[i]) % b;
  }
  c.flatten(a.length);
  return c;
}
int n, A;
int main() {
  // freopen("in.in", "r", stdin);
  while (scanf("%d%d", &n, &A) != EOF) {
    Biginteger ans = 0, base = 1;
    for (int i = 1; i <= n; i++) {
      base = base * A;
      ans = ans + base * i;
    }
    ans.print();
    printf("\n");
  }
  return 0;
}