/**
 * @file    template.cpp
 * @name    p57模板程序
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
  std::vector<int> mySort(std::vector<int> &nums) {
    // 这里填写你的代码
    // assert ：此处提交仅仅用于通过测试
    std::sort(nums.begin(), nums.end());
    return nums;
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
  std::vector<int> after_sort(s.mySort(nums));
  std::cout << after_sort[0];
  for (int i = 1; i < n; i++) {
    std::cout << ' ' << after_sort[i];
  }
  std::cout << std::endl;
  return 0;
}