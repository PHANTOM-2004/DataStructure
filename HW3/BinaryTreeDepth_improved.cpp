#include <iostream>
//  not a good idea

const int MAXN = 1e6 + 5;

struct TreeNode {
  int left;
  int right;
  TreeNode(const int &l = -1, const int &r = -1) : left(l), right(r) {}
} Tree[MAXN];
int n, start;

int GetDepth(const int &root, const int &father) {
  if (root == -1)
    return 0;
  const int l = Tree[root].left == father ? 0 : GetDepth(Tree[root].left, root);
  const int r =
      Tree[root].right == father ? 0 : GetDepth(Tree[root].right, root);
  return std::max(l, r) + 1;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> start;

  for (int i = 0, u, v; i < n; i++) {
    std::cin >> u >> v;
    Tree[i] = TreeNode(u, v);
    if (Tree[u].left == -1)
      Tree[u].left = i;
    else if (Tree[u].right == -1)
      Tree[u].right = i;
    if (Tree[v].left == -1)
      Tree[v].left = i;
    else if (Tree[v].right == -1)
      Tree[v].right = i;
  }
  std::cout << GetDepth(start, -3) << '\n';
  return 0;
}