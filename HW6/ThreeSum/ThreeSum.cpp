#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
  std::vector<int> A;

  void input() {
    int N{};
    std::cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
  }

  void threeSum() {
    std::sort(A.begin(), A.end());

    for (int n1 = 0; n1 < A.size() - 2; n1++) {  // n1最大是size()-3,
      if (n1 > 0 && A[n1] == A[n1 - 1]) continue;
      int n2 = n1 + 1, n3 = A.size() - 1;

      const int target = -A[n1];
      while (n2 < n3) {
        const auto sum = A[n2] + A[n3];
        if (sum < target) {
          n2++;
        } else if (sum > target) {
          n3--;
        } else {
          // assert 此时相等记录答案并且剔除等号
          std::cout << A[n1] << ' ' << A[n2++] << ' ' << A[n3--] << '\n';
          while (n2 < A.size() && A[n2] == A[n2 - 1]) {
            n2++;
          }
          while (n3 >= 0 && A[n3] == A[n3 + 1]) {
            n3--;
          }
        }
      }
    }
  }

 public:
  void solve() {
    input();
    threeSum();
  }
};

Solution T;

int main() {
  freopen("./input5.txt", "r", stdin);
  freopen("./myoutput.txt", "w", stdout);
  T.solve();
}