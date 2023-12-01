#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 120;
int class_time[MAXN];
std::vector<int> G[MAXN];
int dis[MAXN];
int n;
int cnt = 1;
int T[MAXN];

int dfs(int u) {
  if (dis[u])
    return dis[u];
  for (auto &iter : G[u]) {
    dis[u] = std::max(dis[u], dfs(iter));
  }
  return dis[u] += class_time[u];
}

void build_graph() {
  std::cin >> n;
  int c, u;
  for (int i = 1; i <= n; i++) {
    std::cin >> class_time[i] >> c;
    for (int j = 0; j < c; j++) {
      std::cin >> u;
      G[i].push_back(u);
    }
  }
}

int find_max(const bool w) {
  memset(dis, 0, sizeof(int) * (n + 3));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (w)
      ans = std::max(ans, T[i] = dfs(i));
    else
      ans = std::max(ans, dfs(i));
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input1.txt", "r", stdin);
  build_graph();

  int cur_max = find_max(1);
  for (int i = 1; i <= n; i++) {
    std::cout << T[i] << ' ';
    class_time[i]++;
    int post_max = find_max(0);
    class_time[i]--;
    std::cout << (post_max > cur_max) << '\n';
  }

  return 0;
}