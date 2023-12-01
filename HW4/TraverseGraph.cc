#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int MAXN = 1000;

std::vector<int> G[MAXN + 5];
int n = 0, m = 0;
bool vis[MAXN + 5];

void dfs(int father, int u, bool first) {
  if (!first)
    std::cout << ' ';
  std::cout << u;
  vis[u] = 1;
  for (auto &iter : G[u]) {
    if (iter == u || vis[iter])
      continue;
    vis[iter] = 1;
    dfs(u, iter, 0);
  }
}

void bfs(int u) {
  std::queue<int> Q;
  Q.push(u);
  int first = 0;
  vis[u] = 1;
  while (Q.size()) {
    int top = Q.front();
    Q.pop();

    if (first++) {
      std::cout << ' ';
    }
    std::cout << top;
    for (auto &iter : G[top]) {
      if (vis[iter] || iter == top)
        continue;
      vis[iter] = 1;
      Q.push(iter);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("in.txt", "r", stdin);
  std::cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    std::cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for (int i = 0; i < n; i++) {
    if (vis[i])
      continue;
    std::cout << '{';
    dfs(-1, i, 1);
    std::cout << '}';
  }
  memset(vis, 0, sizeof(vis));
  std::cout << '\n';
  for (int i = 0; i < n; i++) {
    if (vis[i])
      continue;
    std::cout << '{';
    bfs(i);
    std::cout << '}';
  }
  std::cout << '\n';
}