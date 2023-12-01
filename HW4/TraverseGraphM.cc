#include <cstring>
#include <iostream>
#include <queue>

const int MAXN = 1000 + 5;

int n = 0, m = 0;
bool vis[MAXN];
bool G[MAXN][MAXN];

void dfs(int u, bool start) {
  if (vis[u])
    return;
  vis[u] = 1;
  if (start)
    std::cout << ' ';
  std::cout << u;
  for (int i = 0; i < n; i++)
    if (!vis[i] && G[i][u])
      dfs(i, 1);
}

void bfs(int u) {
  std::queue<int> Q;
  vis[u] = 1;
  Q.push(u);
  int first = 0;
  while (Q.size()) {
    int top = Q.front();
    Q.pop();

    if (first++) {
      std::cout << ' ';
    }
    std::cout << top;
    for (int i = 0; i < n; i++)
      if (!vis[i] && G[i][top]) {
        Q.push(i);
        vis[i] = 1;
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
    G[u][v] = 1;
    G[v][u] = 1;
  }

  for (int i = 0; i < n; i++) {
    if (vis[i])
      continue;
    std::cout << '{';
    dfs(i, 0);
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