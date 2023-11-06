#include <cstdlib>
#include <iostream>

const int MAXN = 1e4 + 1000;

struct TreeNode {
  unsigned char val;
  int left;
  int right;
  TreeNode(const unsigned char &val = -1, int l = -1, int r = -1)
      : val(val), left(l), right(r) {}
  inline int size() const { return (left == -1) + (right == -1); }
} Tree1[MAXN], Tree2[MAXN];

int n1, n2;
bool vis1[MAXN], vis2[MAXN];
int root1, root2;

void BuildTree(TreeNode Tree[], const int &n, bool vis[]) {
  char l[10], r[10];
  unsigned char val;
  int numl, numr;
  for (int i = 0; i < n; i++) {
    std::cin >> val;
    std::cin >> l >> r;
    if (l[0] != '-') {
      numl = atoi(l);
      vis[numl] = 1;
    } else
      numl = -1;
    if (r[0] != '-') {
      numr = atoi(r);
      vis[numr] = 1;
    } else
      numr = -1;
    Tree[i] = TreeNode(val, numl, numr);
  }
}

int find_root(const bool vis[], const int &n1) {
  for (int i = 0; i < n1; i++)
    if (vis[i] == 0) {
      return i;
    }
  return -1;
}

int getdepth(const TreeNode Tree[], const int &root) {
  if (root == -1)
    return 0;
  int l, r;
  l = getdepth(Tree, Tree[root].left);
  r = getdepth(Tree, Tree[root].right);
  return std::max(l, r) + 1;
}

bool Isomorph(const int &root1, const int &root2) {
  if (root1 == -1 && root2 == -1)
    return true;
  if (Tree1[root1].val != Tree2[root2].val)
    return false;
  if (Tree1[root1].size() != Tree2[root2].size())
    return false;

  const int &l1 = Tree1[root1].left;
  const int &r1 = Tree1[root1].right;
  const int &l2 = Tree2[root2].left;
  const int &r2 = Tree2[root2].right;

  return Isomorph(l1, l2) && Isomorph(r1, r2) ||
         Isomorph(l1, r2) && Isomorph(r1, l2);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  freopen("input10.txt", "r", stdin);

  std::cin >> n1;
  BuildTree(Tree1, n1, vis1);
  std::cin >> n2;
  BuildTree(Tree2, n2, vis2);

  root1 = find_root(vis1, n1);
  root2 = find_root(vis2, n2);

  std::cout << (Isomorph(root1, root2) ? "Yes" : "No") << '\n';
  std::cout << getdepth(Tree1, root1) << '\n';
  std::cout << getdepth(Tree2, root2) << '\n';
}