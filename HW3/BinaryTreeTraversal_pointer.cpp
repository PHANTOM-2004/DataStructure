#include <iostream>
#include <stack>

class TreeNode {
public:
  unsigned char val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(unsigned char val = 0) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *root, **p, *q;
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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;
  std::cin >> msg >> val;
  root = new TreeNode(val);
  stk.push(root);
  p = &(root->left);

  for (int i = 1; i < 2 * n; i++) {
    std::cin >> msg;
    if (msg == "push") {
      std::cin >> val;
      *p = new TreeNode(val);
      stk.push(*p);
      p = &((*p)->left);
    } else {
      q = stk.top();
      stk.pop();
      p = &(q->right);
    }
  }

  postorder(root);
  std::cout << '\n';
  return 0;
}