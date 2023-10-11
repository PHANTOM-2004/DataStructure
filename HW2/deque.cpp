#include <deque>
#include <iostream>
#include <queue>

std::queue<int> Q;
std::deque<int> DQ;
int n;

inline int max() {
  if (DQ.empty())
    return -1;
  return DQ.front();
}

int enqueue(const int &x) {
  if (Q.size() - n == 0)
    return -1;
  while (!DQ.empty() && DQ.back() < x)
    DQ.pop_back();
  DQ.push_back(x);
  Q.push(x);
  return 0;
}

int dequeue() {
  if (Q.empty())
    return -1;
  int ans = Q.front();
  Q.pop();
  if (ans == DQ.front())
    DQ.pop_front();
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // freopen("input1.txt", "r", stdin);
  // freopen("myoutput1.txt", "w", stdout);
  std::cin >> n;
  std::string msg;
  int opt, num;
  while (true) {
    std::cin >> msg;
    switch (msg[0]) {
    case 'd':
      opt = dequeue();
      if (opt == -1) {
        std::cout << "Queue is Empty\n";
      } else
        std::cout << opt << '\n';
      break;
    case 'e':
      std::cin >> num;
      if (enqueue(num) == -1) {
        std::cout << "Queue is Full\n";
      }
      break;
    case 'm':
      opt = max();
      if (opt == -1)
        std::cout << "Queue is Empty\n";
      else
        std::cout << opt << '\n';
      break;
    case 'q':
      while (!Q.empty()) {
        std::cout << Q.front() << " ";
        Q.pop();
      }
      return 0;
      break;
    }
  }
  return 0;
}