#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

const int MAXN = 2100;
std::vector<int> G[MAXN];
bool vis[MAXN];
int n, m;
int dis[MAXN];
int bfs(int u) {
  int tot = 0;
  std::queue<int> Q;
  memset(vis, 0, sizeof(bool) * (n + 3));
  memset(dis, 0, sizeof(bool) * (n + 3));
  vis[u] = 1;
  dis[u] = 0;
  tot++;
  Q.push(u);
  while (Q.size()) {
    int top = Q.front();
    Q.pop();
    for (auto &iter : G[top]) {
      if (vis[iter])
        continue;
      vis[iter] = 1;
      dis[iter] = dis[top] + 1;
      if (dis[iter] > 6)
        continue;
      Q.push(iter);
      tot++;
    }
  }
  return tot;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("in.txt", "r", stdin);

  std::cin >> n >> m;
  /*build graph*/
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    std::cout << i << ": ";
    std::cout << std::setprecision(2) << std::setiosflags(std::ios_base::fixed);
    std::cout << (float)bfs(i) * 100 / n << '%' << '\n';
  }
  return 0;
}