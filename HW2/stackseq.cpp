#include <iostream>
#include <stack>
using std::string;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string ins, outs;
  std::cin >> ins;

  while (std::cin >> outs) {
    std::stack<char> S;
    std::string::iterator out = outs.begin();
    for (auto &iter : ins) {
      S.push(iter);
      while (S.top() == *out) {
        S.pop();
        out++;
        if (S.empty())
          break;
      }
    }
    if (S.empty())
      std::cout << "yes\n";
    else
      std::cout << "no\n";
  }
  return 0;
}