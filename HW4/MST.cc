#include <algorithm>
#include <iostream>

const int MAXN = 1100;
int father[MAXN];
int n, m;
int G[MAXN][MAXN];
int tot;
struct edge {
  int u;
  int v;
  int w;
  edge(int a = 0, int b = 0, int t = 0) {
    u = a;
    v = b;
    w = t;
  }
  bool operator<(const edge &T) const { return w < T.w; }
} T[MAXN * MAXN / 2];

/*并查集*/
int find(int x) {
  if (x == father[x])
    return x;
  return father[x] = find(father[x]);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++)
    father[i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> G[i][j];
    }
  }
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    int fa = find(a);
    int fb = find(b);
    father[fa] = fb;
    G[a][b] = 0;
    G[b][a] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      T[tot++] = edge(i, j, G[i][j]);
    }
  }
  int ans = 0;
  std::sort(T, T + tot);
  for (int i = 0; i < tot; i++) {
    int fu = find(T[i].u);
    int fv = find(T[i].v);
    if (fu != fv && G[T[i].u][T[i].v]) {
      father[fu] = fv;
      ans += T[i].w;
    }
  }
  std::cout << ans << '\n';
  return 0;
}