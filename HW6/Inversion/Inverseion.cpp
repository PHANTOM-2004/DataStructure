#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
  int N;
  std::vector<int> elem;
  std::vector<int> A;

  int mergeSortCount(const int low, const int high) {
    if (high - low < 2) return 0;
    int res = 0;
    const int mid = (low + high) / 2;
    res += mergeSortCount(low, mid);
    res += mergeSortCount(mid, high);

    res += mergeCount(low, mid, high);
    return res;
  }

  int mergeCount(const int low, const int mid, const int high) {
    int res = 0;
    int i = 0, j = mid, tot = low;
    const int la = mid - low;
    if (A.size() < la) A.resize(la);
    for (int t = 0; t < la; t++) A[t] = elem[t + low];

    while (i < la && j < high) {
      if (A[i] <= elem[j]) {
        elem[tot++] = A[i++];
      } else {
        elem[tot++] = elem[j++];
        res += mid - (i + low);
      }
    }
    while (i < la) {
      elem[tot++] = A[i++];
    }

    return res;
  }

  void input() {
    elem.resize(N);
    for (int i = 0; i < N; i++) std::cin >> elem[i];
  }

 public:
  void solve() {
    while (std::cin >> N) {
      if (!N) break;
      input();
      std::cout << mergeSortCount(0, N) << '\n';
    };
  }
};

Solution T;
int main() {
  freopen("./input9.txt", "r", stdin);
  freopen("./myoutput.txt", "w", stdout);
  T.solve();
}
