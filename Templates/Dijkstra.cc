#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

class Dijkstra {
  enum { MAXN = (int)1e5 + 5, MAXM = (int)2e5 + 5 };
  int n, m, s;
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
    node(int i = 0, int w = 0) : index(i), w(w) {}
    bool operator<(const node &T) const { return w > T.w; }
  };
  std::vector<edge> G[MAXN];

  void build_G() {
    std::cin >> n >> m >> s;
    int u, v, w;
    for (int i = 0; i < m; i++) {
      std::cin >> u >> v >> w;
      G[u].push_back(edge(v, w));
      // G[v].push_back(edge(u, w));
    }
  }

  void shortest_path() {
    std::priority_queue<node> Q;
    for (int i = 0; i <= n; i++)
      dis[i] = INT_MAX;
    Q.push(node(s, dis[s] = 0));
    while (Q.size()) {
      auto top = Q.top().index;
      Q.pop();
      if (vis[top])
        continue;
      vis[top] = 1;
      for (const auto &iter : G[top]) {
        const auto &v = iter.v;
        const auto &w = iter.w;
        if ((long long)dis[v] > (long long)w + dis[top]) {
          dis[v] = w + dis[top];
          Q.push(node(v, dis[v]));
        }
      }
    }
  }

public:
  Dijkstra() { memset(vis, 0, sizeof(vis)); }
  void solve() {
    build_G();
    shortest_path();
    for (int i = 1; i <= n; i++) {
      std::cout << dis[i] << " \n"[i == n];
    }
  }
};

Dijkstra D;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  D.solve();
  return 0;
}
