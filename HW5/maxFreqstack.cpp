/**
 * @name    template.cpp
 * @brief   p142模板程序
 * @date    2022-12-02
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
#include <unordered_map>
class FreqStack {
private:
  std::unordered_map<int, int> frequency;
  std::unordered_map<int, std::stack<int>> stk;
  int max_frequency;

public:
  FreqStack() { max_frequency = 0; }

  void push(int val) {
    auto t = ++frequency[val];
    stk[t].push(val);
    max_frequency = std::max(t, max_frequency);
  }

  int pop() {
    auto t = stk[max_frequency].top();
    stk[max_frequency].pop();
    frequency[t]--;
    if (stk[max_frequency].empty()) {
      max_frequency--;
    }
    return t;
  }
};

/********************************/
/*     以上是你需要提交的代码     */
/********************************/

int main() {
  int n;
  std::cin >> n;
  FreqStack fs;
  while (n--) {
    std::string order;
    std::cin >> order;
    if (order == "push") {
      int val;
      std::cin >> val;
      fs.push(val);
    } else if (order == "pop") {
      std::cout << fs.pop() << std::endl;
    }
  }
  return 0;
}
