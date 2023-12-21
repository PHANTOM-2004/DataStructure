/**
 * @file    template.cpp
 * @name    p138模板程序
 * @date    2022-11-20
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

/********************************/
/*     以下是你需要提交的代码     */
/********************************/
#include <unordered_map>
class Solution {
  int count;
  int m, n;
  std::unordered_map<std::string, int> pos;
  std::vector<char> vis;
  int find(std::vector<std::vector<std::string>> &old_chart) {
    vis.resize(count, 0);
    int loop = 0;
    for (int i = 0; i < count; i++) {
      if (vis[i] == 1)
        continue;
      int t = i;
      while (vis[t] == 0) {
        vis[t] = 1;
        auto &cur = old_chart[t / m][t % m];
        t = pos[cur];
      }
      loop++;
    }
    return count - loop;
  }

public:
  Solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    count = 0;
  }
  int solve(std::vector<std::vector<std::string>> &old_chart,
            std::vector<std::vector<std::string>> &new_chart) {
    // 这里填写你的代码
    n = new_chart.size();
    m = new_chart[0].size();
    count = m * n;
    // build
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        pos[new_chart[i][j]] = i * m + j;
      }
    }

    return find(old_chart);
  }
};
/********************************/
/*     以上是你需要提交的代码     */
/********************************/

int main() {

  freopen("input10.txt", "r", stdin);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::string>> old_chart(n,
                                                  std::vector<std::string>(m));
  std::vector<std::vector<std::string>> new_chart(n,
                                                  std::vector<std::string>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> old_chart[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> new_chart[i][j];
    }
  }

  Solution s;
  std::cout << s.solve(old_chart, new_chart) << std::endl;
  return 0;
}
