#include <algorithm>
#include <cstring>
#include <iostream>

class Kruskal {
  enum { MAXN = 5010, MAXM = 200000 + 10 };
  int m, n;
  int MST;
  int father[MAXN];
  struct edge {
    int u;
    int v;
    int w;
    edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
    bool operator<(const edge &T) const { return w < T.w; }
  } G[MAXM];

private:
  int find(int x) {
    if (x == father[x])
      return x;
    return father[x] = find(father[x]);
  }

  void build_G() {
    std::cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++) {
      std::cin >> u >> v >> w;
      G[i] = edge(u, v, w);
    }
    for (int i = 0; i <= n; i++) {
      father[i] = i;
    }
  }
  bool construct_MST() {
    int tot = 0;
    std::sort(G, G + m);
    for (int i = 0; i < m; i++) {
      auto &u = G[i].u;
      auto &v = G[i].v;
      int fu = find(u);
      int fv = find(v);
      if (fu == fv)
        continue;
      father[fu] = fv;
      tot++;
      MST += G[i].w;
    }
    return tot == n - 1;
  }

public:
  Kruskal() { MST = 0; }
  void solve() {
    build_G();
    if (construct_MST()) {
      std::cout << MST << '\n';
    } else {
      std::cout << "orz\n";
    }
  }
};

Kruskal K;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  K.solve();
  return 0;
}