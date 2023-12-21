#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class Longest {
  int n, m;
  std::vector<int> arr;
  std::vector<int> sum;

public:
  Longest() {}
  void solve() {
    build();
    int q = 0;
    for (int i = 0; i < m; i++) {
      std::cin >> q;
      std::cout << find_len(q) << " \n"[i == m - 1];
    }
  }

private:
  void build() {
    std::cin >> n >> m;
    arr.resize(n + 1);
    sum.resize(n + 1);
    arr[0] = 0;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++) {
      sum[i] = arr[i] + sum[i - 1];
    }
  }
  int find_len(const int q) {
    int l = 1, r = n, mid = 0, ans = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      if (sum[mid] <= q) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }
};

Longest Solution;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  freopen("input6.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  Solution.solve();
  return 0;
}