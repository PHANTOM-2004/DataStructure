#include <iostream>
#include <stack>

class TreeNode {
public:
  unsigned char val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(unsigned char val = 0) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *root;
int n;
std::string msg;
unsigned char val;
std::stack<TreeNode *> stk;

void postorder(TreeNode *root) {
  if (root == nullptr)
    return;
  postorder(root->left);
  postorder(root->right);
  std::cout << root->val;
}

void buildtree() {
  TreeNode *p = root;
  bool flag = 0;

  for (int i = 1; i < 2 * n; i++) {
    std::cin >> msg;
    if (msg == "push") {
      std::cin >> val;
      TreeNode *newnode = new TreeNode(val);
      if (!flag) {
        p->left = newnode;
        p = p->left;
      } else {
        p->right = newnode;
        p = p->right;
      }
      stk.push(p);
      flag = 0;
    } else if (msg == "pop") {
      p = stk.top();
      stk.pop();
      flag = 1;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;
  std::cin >> msg >> val;
  root = new TreeNode(val);
  stk.push(root);
  buildtree();
  postorder(root);
  std::cout << '\n';
  return 0;
}