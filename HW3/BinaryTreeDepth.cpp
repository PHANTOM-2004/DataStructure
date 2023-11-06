#include <iostream>
#include <vector>

const int MAXN = 1e6 + 5;
std::vector<int> G[MAXN];
int dis[MAXN];
int n;
int start;
int depth;

void dfs(int father, int u) {
  depth = std::max(depth, dis[u]);
  for (auto iter : G[u]) {
    if (iter == father)
      continue;
    dis[iter] = dis[u] + 1;
    dfs(u, iter);
  }
}

int main() {
  freopen("input10.txt", "r", stdin);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> start;
  for (int i = 0, u, v; i < n; i++) {
    std::cin >> u >> v;
    if (u != -1) {
      G[i].push_back(u);
      G[u].push_back(i);
    }
    if (v != -1) {
      G[v].push_back(i);
      G[i].push_back(v);
    }
  }
  dfs(-1, start);
  std::cout << depth;
  return 0;
}