#include <iostream>
#include <queue>

const int MAXN = 1e3 + 5;
bool map[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct point {
  int x;
  int y;
};
std::queue<point> Q;

int n, m, cnt;

const int step[][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input4.txt", "r", stdin);
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> map[i][j];
    }
  }

  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (vis[i][j] || map[i][j] == 0)
        continue;
      cnt++;
      Q.push(point{i, j});
      vis[i][j] = 1;
      while (!Q.empty()) {
        point top = Q.front();
        Q.pop();
        int x = top.x, y = top.y;
        for (int k = 0; k < 4; k++) {
          int next_x = x + step[k][0];
          int next_y = y + step[k][1];
          if (map[next_x][next_y] == 0 || vis[next_x][next_y] || next_x < 0 ||
              next_x >= n || next_y < 0 || next_y >= m)
            continue;
          Q.push(point{next_x, next_y});
          vis[next_x][next_y] = 1;
        }
      }
    }
  }

  std::cout << cnt << '\n';
  return 0;
}