#include <iostream>
#include <stack>
std::string msg;
std::stack<int> stk;

int treedepth, btreedepth;
int cur_depth, bcur_depth;
int cnt = 0;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  while (true) {
    std::cin >> msg;
    cnt++;
    if (msg[0] == '#')
      return 0;
    treedepth = btreedepth = cur_depth = bcur_depth = 0;
    while (!stk.empty())
      stk.pop();
    stk.push(0);
    for (auto &ch : msg) {
      if (ch == 'd') {
        cur_depth++;
        bcur_depth++;
        stk.push(bcur_depth);
      } else {
        cur_depth--;
        bcur_depth = stk.top();
        stk.pop();
      }
      treedepth = std::max(treedepth, cur_depth);
      btreedepth = std::max(btreedepth, bcur_depth);
    }
    std::cout << "Tree " << cnt << ": " << treedepth << " => " << btreedepth
              << '\n';
  }
  return 0;
}