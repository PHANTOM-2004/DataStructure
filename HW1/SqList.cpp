#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <vector>
struct stu {
  std::string no;
  std::string name;
  stu(std::string n = "", std::string s = "") {
    no = n;
    name = s;
  }
};

std::vector<stu> L;

int InsertElem(int k, stu t) {
  if (k < 0 || k > L.size())
    return -1;
  L.push_back(stu{"", ""});
  for (int i = L.size() - 1; i >= k + 1; i--)
    L[i] = L[i - 1];
  L[k] = t;
  return 0;
}
int RemoveElem(int k) {
  if (k < 0 || k >= L.size())
    return -1;
  for (int i = k + 1; i < L.size(); i++)
    L[i - 1] = L[i];
  L.pop_back();
  return 0;
}
void Print(int i) {
  std::cout << i + 1 << " " << L[i].no << " " << L[i].name << '\n';
}

void CheckName(std::string N) {
  for (int i = 0; i < L.size(); i++) {
    if (L[i].name == N) {
      Print(i);
      return;
    }
  }
  std::cout << "-1\n";
}

void CheckNo(std::string n) {
  for (int i = 0; i < L.size(); i++) {
    if (L[i].no == n) {
      Print(i);
      return;
    }
  }
  std::cout << "-1\n";
}

char str[300];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    stu tmp;
    std::cin >> tmp.no >> tmp.name;
    L.push_back(tmp);
  }
  char s[100], s1[100];

  int no = 0, pos = 0;
  while (1) {
    std::cin.getline(str, 300);
    if (str[0] == 'e')
      break;
    switch (str[0]) {
    case 'i':
      sscanf(str, "insert %d %s %s", &pos, s1, s);
      std::cout << InsertElem(pos - 1, stu(s1, s)) << '\n';
      break;
    case 'r':
      sscanf(str, "remove %d", &pos);
      std::cout << RemoveElem(pos - 1) << '\n';
      break;
    case 'c':
      if (str[7] == 'a') {
        sscanf(str, "check name %s", s);
        CheckName(s);
      } else {
        sscanf(str, "check no %s", s);
        CheckNo(s);
      }
      break;
    }
  }
  std::cout << L.size() << '\n';
  return 0;
}
