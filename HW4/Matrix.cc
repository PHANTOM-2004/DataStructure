#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int MAXK = 400 + 5;

int n, k, m;

int ans[MAXK][MAXK];
int row[MAXK];
int col[MAXK];
int indegree[MAXK];
int pos[MAXK];

bool topo_sort(int arr[], int t) {
  std::vector<int> G[MAXK];
  for (int i = 0; i < t; i++) {
    int a, b;
    std::cin >> a >> b;
    indegree[b]++;
    G[a].push_back(b);
  }
  std::queue<int> Q;
  for (int i = 1; i <= k; i++) {
    if (indegree[i] == 0)
      Q.push(i);
  }

  int tot = 1;
  while (Q.size()) {
    int top = Q.front();
    Q.pop();
    arr[tot++] = top;
    for (auto &iter : G[top]) {
      indegree[iter]--;
      if (indegree[iter] == 0)
        Q.push(iter);
    }
  }
  return tot > k;
}

void build_matrix() {
  for (int i = 1; i <= k; i++)
    pos[col[i]] = i;
  for (int i = 1; i <= k; i++) {
    ans[i][pos[row[i]]] = row[i];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  // freopen("in.txt", "r", stdin);
  std::cin >> k >> n >> m;

  bool f1 = topo_sort(row, n);
  memset(indegree, 0, sizeof(indegree));
  bool f2 = topo_sort(col, m);
  if (!f1 || !f2) {
    std::cout << -1 << '\n';
    return 0;
  }
  build_matrix();
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++)
      std::cout << ans[i][j] << " \n"[j == k];
  return 0;
}