#include <cstring>
#include <iostream>
#include <stack>

class EulerGraph {
  enum { MAXM = 1100, MAXN = 500 };
  int G[MAXN + 3][MAXN + 3]; // 存储每个点的度
  int degree[MAXN + 3];
  int m;
  int max_index;
  std::stack<int> ans;

private:
  void build_graph() {
    std::cin >> m;
    for (int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      max_index = std::max(max_index, std::max(u, v));
      G[u][v]++;
      G[v][u]++;
      degree[u]++;
      degree[v]++;
    }
  }

  void dfs(const int cur) {
    for (int i = 1; i <= max_index; i++) {
      if (G[cur][i] == 0)
        continue;
      G[i][cur]--;
      G[cur][i]--;
      dfs(i);
    }
    ans.push(cur);
  }

public:
  EulerGraph() {
    memset(G, 0, sizeof(G));
    memset(degree, 0, sizeof(degree));
    max_index = 0;
  }

  void solve() {
    build_graph();
    int start = 0;
    for (int i = 1; i <= max_index; i++) {
      if (degree[i] % 2) {
        start = i;
        break;
      }
    }
    if (start == 0) {
      for (int i = 1; i <= max_index; i++) {
        if (degree[i]) {
          start = i;
          break;
        }
      }
    }
    dfs(start);
    while (ans.size()) {
      std::cout << ans.top() << '\n';
      ans.pop();
    }
  }
} Solution;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("P2731_6.in", "r", stdin);
  Solution.solve();
  return 0;
}