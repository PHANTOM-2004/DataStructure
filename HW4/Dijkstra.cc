#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using pii = std::pair<int, int>;

const int MAXN = 1100;
std::vector<pii> G[MAXN];
int grass[MAXN];
int dis[MAXN];
bool vis[MAXN];
int n, h, r, m;
int step[MAXN][MAXN];

void dijkstra(int start) {
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
  memset(vis, 0, sizeof(bool) * (n + 4));
  memset(dis, 0x3f, sizeof(int) * (n + 4));
  
  dis[start] = 0;
  Q.push(pii(0, start));
  while (Q.size()) {
    auto top = Q.top();
    Q.pop();
    int distance = top.first;
    int i = top.second;
    if (vis[i])
      continue;
    vis[i] = 1;
    for (auto &iter : G[i]) {
      int v = iter.second;
      int w = iter.first;
      if (distance + w < dis[v]) {
        dis[v] = distance + w;
        Q.push(pii(dis[v], v));
      }
    }
  }
}

void build_graph() {
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, w, y;
    std::cin >> x >> y >> w;
    G[x].push_back(pii(w, y));
    G[y].push_back(pii(w, x));
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  freopen("input1.txt", "r", stdin);
  build_graph();

  std::cin >> h >> r;
  for (int i = 1; i <= h; i++) {
    std::cin >> grass[i];
    dijkstra(grass[i]);
    for (int j = 1; j <= n; j++) {
      step[grass[i]][j] = dis[j];
    }
  }

  for (int i = 0; i < r; i++) {
    int start, end;
    std::cin >> start >> end;
    int ans = 0x7f7f7f7f;
    for (int j = 1; j <= h; j++) {
      ans = std::min(ans, step[grass[j]][start] + step[grass[j]][end]);
    }
    std::cout << ans << '\n';
  }
  return 0;
}