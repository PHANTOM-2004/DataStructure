#include <cstring>
#include <iostream>
#include <queue>

class Prim {
  enum { MAXN = 5010, MAXM = 200000 + 10 };
  int m, n;
  int MST;
  int dis[MAXN];
  bool vis[MAXN];
  struct edge {
    int v;
    int w;
    edge(int v = 0, int w = 0) : v(v), w(w) {}
  };
  struct node {
    int index;
    int w;
    node(int index = 0, int w = 0) : index(index), w(w) {}
    bool operator<(const node &T) const { return w > T.w; }
  };
  std::vector<edge> G[MAXN];

  void build_G() {
    std::cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++) {
      std::cin >> u >> v >> w;
      G[u].push_back(edge(v, w));
      G[v].push_back(edge(u, w));
    }
  }

  bool construct_MST() {
    int tot = 0;
    std::priority_queue<node> Q;
    dis[1] = 0;
    Q.push(node(1, dis[1]));
    while (Q.size()) {
      int u = Q.top().index;
      Q.pop();
      if (vis[u])
        continue;
      vis[u] = 1;
      MST += dis[u];
      tot++;
      for (const auto &iter : G[u]) {
        const auto &v = iter.v;
        const auto &w = iter.w;
        if (w < dis[v]) {
          dis[v] = w;
          Q.push(node(v, dis[v]));
        }
      }
    }
    return tot == n;
  }

public:
  Prim() {
    memset(dis, 0x3f, sizeof(dis));
    MST = 0;
  }
  void solve() {
    build_G();
    if (construct_MST())
      std::cout << MST << '\n';
    else
      std::cout << "orz\n";
  }
};

Prim P;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  P.solve();
  return 0;
}