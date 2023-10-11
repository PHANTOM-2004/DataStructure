#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

std::stack<char> _operator;
std::stack<bool> _number;
std::unordered_map<char, int> mp = {{'!', 3}, {'&', 2}, {'|', 1}};

void calc(char oper) {
  bool a = 0, b = 0;
  switch (oper) {
  case '|':
    a = _number.top();
    _number.pop();
    b = _number.top();
    _number.pop();
    _number.push(a | b);
    break;
  case '&':
    a = _number.top();
    _number.pop();
    b = _number.top();
    _number.pop();
    _number.push(a & b);
    break;
  case '!':
    a = _number.top();
    _number.pop();
    _number.push(!a);
    break;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string line;

  int cnt = 0;
  while (std::getline(std::cin, line)) {
    cnt++;
    line = "(" + line + ")";
    for (auto &ch : line) {
      if (ch == ' ' || ch == '\r')
        continue;
      if (ch == 'V' || ch == 'F') {
        _number.push(ch == 'V');
        continue;
      }
      if (_operator.empty())
        _operator.push(ch);
      else if (ch == '(') {
        _operator.push(ch);
      } else if (ch == ')') {
        while (_operator.top() != '(') {
          calc(_operator.top());
          _operator.pop();
        }
        _operator.pop(); // ignore'('
      } else {
        while (!_operator.empty() &&
               (ch != '!' && mp[ch] <= mp[_operator.top()] ||
                ch == '!' && mp[ch] < mp[_operator.top()])) {
          char op = _operator.top();
          calc(op);
          _operator.pop();
        }
        _operator.push(ch);
      }
    }
    std::cout << "Expression " << cnt << ": " << (_number.top() ? 'V' : 'F')
              << '\n';
    _number.pop();
    // std::cout << _number.top();
    // std::cout << _number.size() << " " << _operator.size() << " "
    //           << _number.top();
  }

  return 0;
}