#include <iostream>
#include <stack>

std::stack<int> stk;

std::string line;
int ans = 0;
int pos = 0;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input4.txt", "r", stdin);
  stk.push(-1);
  std::cin >> line;
  const int l = line.length();
  for (int i = 0; i < l; i++) {
    char &ch = line[i];
    if (ch == '(') {
      stk.push(i);
    } else {
      stk.pop();
      if (stk.empty()) {
        stk.push(i);
      } else {
        if (i - stk.top() > ans) {
          ans = i - stk.top();
          pos = stk.top() + 1;
        }
      }
    }
  }

  std::cout << ans << " " << pos << '\n';
  return 0;
}
