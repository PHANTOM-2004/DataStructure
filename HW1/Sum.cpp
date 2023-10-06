#include <cstring>
#include <iostream>

using namespace std;
#define maxn 500
struct Biginteger {
  int len = 0;
  int a[maxn];
  Biginteger(int x = 0) {
    memset(a, 0, sizeof(a));
    for (len = 1; x; len++) {
      a[len] = x % 10;
      x /= 10;
    }
    len--;
  }

  int &operator[](int i) { return a[i]; }
  void print() {
    for (int j = max(len, 1); j >= 1; j--) {
      printf("%d", a[j]);
    }
  }

  void flatten(int L) {
    len = L;
    for (int i = 1; i <= len; i++) {
      a[i + 1] = a[i + 1] + a[i] / 10;
      a[i] = a[i] % 10;
    }
    for (; !a[len];)
      len--;
  }
};

Biginteger operator+(Biginteger a, Biginteger b) {
  Biginteger c;
  int len = max(a.len, b.len);
  for (int i = 1; i <= len; i++)
    c[i] = c[i] + a[i] + b[i];
  c.flatten(len + 1);
  return c;
}

Biginteger operator*(Biginteger a, int b) {
  Biginteger c;
  int len = a.len;
  for (int i = 1; i <= len; i++)
    c[i] = a[i] * b;
  c.flatten(len + 11);
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