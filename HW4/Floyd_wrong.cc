#include <algorithm>
#include <cstring>
#include <iostream>

const int MAXN = 1010;
int f[MAXN][MAXN];
int Grass[MAXN];

int n, m;
int h, r;
void floyd() {
  for (int k = 1; k <= h; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j] = std::min(f[i][j], f[i][Grass[k]] + f[Grass[k]][j]);
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  memset(f, 0x3f, sizeof(f));
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    f[x][y] = w;
    f[y][x] = w;
  }

  std::cin >> h >> r;
  for (int i = 0; i < h; i++) {
    std::cin >> Grass[i];
  }
  std::sort(Grass + 1, Grass + 1 + h);
  floyd();

  for (int i = 0; i < r; i++) {
    int s, e;
    std::cin >> s >> e;
  }
}