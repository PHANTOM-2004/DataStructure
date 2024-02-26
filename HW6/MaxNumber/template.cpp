/**
 * @file    template.cpp
 * @name    模板程序
 * @date    2022-11-22
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
#include <vector>
using namespace std;

/********************************/
/*     以下是你需要提交的代码     */
/********************************/
class Solution {
 public:
  std::string largestNumber(std::vector<int>& nums) {
    // 这里填写你的代码
    std::string res;
    res.reserve(nums.size() * 4);
    auto cmp = [](const int a, const int b) {
      const auto s1 = std::to_string(a), s2 = std::to_string(b);
      if (s1 + s2 > s2 + s1) return true;
      return false;
    };
    std::sort(nums.begin(), nums.end(), cmp);
    for (auto iter : nums) {
      res.append(std::to_string(iter));
    }
    return res;
  }
};
/********************************/
/*     以上是你需要提交的代码     */
/********************************/

int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }
  Solution s;
  std::cout << s.largestNumber(nums) << std::endl;
  return 0;
}