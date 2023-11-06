#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::string preorder;
std::string inorder;
int cnt = 0;

void build(int x, int y, int p, int q, std::vector<char> &ans) {
  if (x > y || p > q)
    return;
  cnt++;
  if (cnt > preorder.size() + 1)
    return;
  int index = inorder.find(preorder[x]);
  build(x + 1, x + index - p, p, index - 1, ans);
  build(x + index - p + 1, y, index + 1, q, ans);
  ans.push_back(preorder[x]);
  return;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input5.txt", "r", stdin);
  while (std::cin >> preorder >> inorder) {
    std::vector<char> ans;
    cnt = 0;
    build(0, preorder.length() - 1, 0, inorder.length() - 1, ans);
    if (cnt <= preorder.size() + 1) {
      for (auto &iter : ans) {
        std::cout << iter;
      }
      std::cout << '\n';
    } else
      std::cout << "Error\n";
  }
  return 0;
}