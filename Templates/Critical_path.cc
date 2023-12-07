#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class CriticalPath {
  enum { MAXN = 200 };
  std::vector<int> G[MAXN];
  std::stack<int> S;
  int n, m;
  int time[MAXN];
  int indegree[MAXN];
  int outdegree[MAXN];
  int ve[MAXN];
  int vl[MAXN];

public:
  CriticalPath() {
    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));
  }
  void build_graph() {
    std::cin >> n;
    int c = 0;
    for (int i = 1; i <= n; i++) {
      std::cin >> time[i];
      std::cin >> c;
      indegree[i] = c;
      for (int j = 1, x; j <= c; j++) {
        std::cin >> x;
        G[x].push_back(i);
        outdegree[x]++;
      }
    }
    // 接入汇点n+1
    time[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
      if (outdegree[i] == 0) {
        G[i].push_back(n + 1);
        indegree[n + 1]++;
      }
    }
  }
  // find ve
  bool find_ve() {
    int tot = 0;
    std::queue<int> Q;
    for (int i = 1; i <= n; i++)
      if (indegree[i] == 0) {
        Q.push(i);
      }

    for (int i = 1; i <= n; i++)
      ve[i] = time[i];
    while (Q.size()) {
      tot++;
      int top = Q.front();
      Q.pop();
      S.push(top);

      for (const auto &iter : G[top]) {
        --indegree[iter];
        if (indegree[iter] == 0)
          Q.push(iter);
        ve[iter] = std::max(ve[iter], ve[top] + time[iter]);
      }
    }
    return tot >= n;
  }

  void find_vl() {
    for (int i = 1; i <= n + 1; i++) {
      vl[i] = ve[n + 1];
    }
    while (S.size()) {
      int top = S.top();
      S.pop();
      for (const auto &iter : G[top]) {
        vl[top] = std::min(vl[top], vl[iter] - time[iter]);
      }
    }
  }

  void solve() {
    build_graph();
    find_ve();
    find_vl();
    for (int i = 1; i <= n; i++) {
      std::cout << ve[i] << ' ';
      std::cout << (ve[i] == vl[i]) << '\n';
    }
  }
};
CriticalPath solution;
int main() {
  freopen("in.txt", "r", stdin);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // solution.build_graph();
  // solution.find_ve();
  // solution.find_vl();
  solution.solve();
  return 0;
}