
#include <iostream>

class BST {
  struct TreeNode {
    int val;
    int cnt;
    TreeNode *left;
    TreeNode *right;

    TreeNode(const int val = 0, const int cnt = 0, TreeNode *l = nullptr,
             TreeNode *r = nullptr)
        : val(val), cnt(cnt), left(l), right(r) {}
  } *root;

  TreeNode *search_node(const int v) const {
    TreeNode *cur = root;
    while (cur != nullptr) {
      if (v > cur->val) {
        cur = cur->right;
      } else if (v < cur->val) {
        cur = cur->left;
      } else {
        break;
      }
    }
    return cur;
  }

  int count_node(const int v) const {
    const auto p = search_node(v);
    return p == nullptr ? 0 : p->cnt;
  }
  TreeNode *find_min() const {
    if (root == nullptr)
      return nullptr;

    TreeNode *cur = root;
    while (cur->left != nullptr) {
      cur = cur->left;
    }
    return cur;
  }
  TreeNode *search_pre(TreeNode *cur, const int v,
                       TreeNode *ans = nullptr) const {
    if (cur == nullptr)
      return ans;
    if (v <= cur->val) {
      return search_pre(cur->left, v, ans);
    } else {
      return search_pre(cur->right, v, cur);
    }
  }

  void insert_node(const int v) {
    if (root == nullptr) {
      root = new TreeNode(v, 1);
      return;
    }
    TreeNode *cur = root, *pre = nullptr;

    while (cur != nullptr) {
      if (cur->val == v) {
        cur->cnt++;
        return;
      }

      pre = cur;
      if (v > cur->val) {
        cur = cur->right;
      } else {
        cur = cur->left;
      }
    }

    auto new_node = new TreeNode(v, 1);
    if (v < pre->val) {
      pre->left = new_node;
    } else {
      pre->right = new_node;
    }
  }

  bool delete_node(const int v) {
    if (root == nullptr)
      return false;

    TreeNode *cur = root, *pre = nullptr;
    while (cur != nullptr) {
      if (v == cur->val) {
        if (cur->cnt > 1) {
          cur->cnt--;
          return true;
        } else
          break;
      }
      pre = cur;
      if (v > cur->val) {
        cur = cur->right;
      } else {
        cur = cur->left;
      }
    }

    if (cur == nullptr) {
      return false;
    }

    //  一个孩子或者没有孩子
    if (cur->left == nullptr || cur->right == nullptr) {
      TreeNode *cur_child = nullptr;
      cur_child = cur->left != nullptr ? cur->left : cur->right;
      if (cur == root) {
        root = cur_child;
      } else {
        if (pre->left == cur) {
          pre->left = cur_child;
        } else {
          pre->right = cur_child;
        }
      }
      delete cur;
      return true;
    }

    // 两个孩子的情况
    TreeNode *tmp = cur->right;
    // 右子树最小
    while (tmp->left != nullptr) {
      tmp = tmp->left;
    }
    int tval = tmp->val, tcnt = tmp->cnt;
    delete_node(tval);

    cur->val = tval;
    cur->cnt = tcnt;
    return true;
  }

public:
  BST() {}
  void solve() {
    int n, v, op;
    std::cin >> n;
    TreeNode *p;
    // int tot = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> op;
      switch (op) {
      case 1:
        std::cin >> v;
        insert_node(v);
        break;
      case 2:
        std::cin >> v;
        if (delete_node(v) == false)
          //   std::cout << ++tot << ": op=2 v=" << v << "  ";
          std::cout << "None\n";
        break;
      case 3:
        std::cin >> v;
        std::cout << count_node(v) << '\n';
        break;
      case 4:
        p = find_min();
        if (p == nullptr)
          std::cout << "-1\n";
        else
          std::cout << p->val << '\n';
        break;
      case 5:
        std::cin >> v;
        p = search_pre(root, v);
        if (p == nullptr)
          std::cout << "None\n";
        else
          std::cout << p->val << '\n';
        break;
      }
    }
  }
};

BST Solution;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input6.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  Solution.solve();
}