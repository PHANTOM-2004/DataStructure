#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 1005;
int father[MAXN];
int deep[MAXN];
int uf[MAXN];
std::vector<int> G[MAXN];

void dfs(int u) {
  for (auto &iter : G[u]) {
    if (iter == father[u])
      continue;
    father[iter] = u;
    deep[iter] = deep[u] + 1;
    dfs(iter);
  }
}

int Query(int u, int v) {
  if (deep[u] < deep[v]) // u中存更深的点
    std::swap(u, v);
  while (deep[u] != deep[v])
    u = father[u]; // 将u向上提
  while (u != v) {
    u = father[u];
    v = father[v];
  }
  return u;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input10.txt", "r", stdin);
  int T = 0;
  std::cin >> T;

  while (T--) {
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i <= n; i++)
      if (!G[i].empty())
        G[i].clear();

    memset(deep, 0, sizeof(deep));
    memset(father, 0, sizeof(father));
    for (int i = 1; i <= n; i++)
      uf[i] = i;
    for (int i = 1, a, b; i < n; i++) {
      std::cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
      uf[b] = a;
    }
    int ancester = 1;
    while (uf[ancester] != ancester)
      ancester = uf[ancester];
    // std::cout << "*" << ancester << "*\n";
    father[ancester] = -1;
    deep[1] = 0;
    dfs(ancester);
    for (int i = 0, x, y; i < m; i++) {
      std::cin >> x >> y;
      std::cout << Query(x, y) << '\n';
    }
  }
  return 0;
}