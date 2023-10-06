#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> mp{
    {"Spade", 0}, {"Heart", 1}, {"Club", 2}, {"Diamond", 3}};
const char *color[] = {"Spade", "Heart", "Club", "Diamond"};
const char *n[] = {"-1", "A", "2", "3",  "4", "5", "6",
                   "7",  "8", "9", "10", "J", "Q", "K"};

struct Poker {
  int number;
  int color;
  bool operator<(const Poker &a) const { return number < a.number; }
  Poker(int n = 0, int c = 0) {
    number = n;
    color = c;
  }
};

std::ostream &operator<<(std::ostream &output, Poker &T) {
  output << color[T.color] << " " << n[T.number];
  return output;
}

std::list<Poker> L;

int xchg(std::string T) {
  if (T == "10")
    return 10;
  int n = T[0] - '0';
  if (n >= 2 && n <= 9)
    return n;
  switch (T[0]) {
  case 'A':
    return 1;
  case 'J':
    return 11;
  case 'Q':
    return 12;
  case 'K':
    return 13;
  }
  return -1;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // freopen("input6.txt", "r", stdin);
  // freopen("output6.out", "w", stdout);
  int n;
  std::cin >> n;
  std::string msg, c, number;
  while (n--) {
    std::cin >> msg;
    switch (msg[0]) {
    case 'R':
      L.reverse();
      break;
    case 'P':
      if (L.size()) {
        std::cout << L.front() << '\n';
        L.pop_front();
      } else {
        std::cout << "NULL\n";
      }
      break;
    case 'A':
      std::cin >> c >> number;
      L.push_back(Poker{xchg(number), mp[c]});
      break;
    case 'E':
      std::cin >> c;
      int color = mp[c];
      std::vector<Poker> tmp(0);
      std::list<Poker>::iterator it;
      for (it = L.begin(); it != L.end();) {
        if (it->color == color) {
          tmp.push_back(*it);
          it = L.erase(it);
        } else {
          it++;
        }
      }
      std::sort(tmp.begin(), tmp.end());
      for (int i = tmp.size() - 1; i >= 0; i--)
        L.push_front(tmp[i]);
      break;
    }
  }
  for (auto &iter : L) {
    std::cout << iter << '\n';
  }
  return 0;
}
