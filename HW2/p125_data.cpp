/**
 * @file    p125_data.cpp
 * @name    p125随机测试数据生成程序
 * @date    2022-09-25
 */

#include <fstream>
#include <iostream>
#include <vector>

class Solution {
public:
  Solution(std::string str) : s(str), max_length(0) {}
  ~Solution() {}

  void slove() {
    std::vector<int> dp(s.length());
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        continue;
      }

      if (i > 0 && s[i - 1] == '(') {
        dp[i] = (i > 1 ? dp[i - 2] : 0) + 2;
      } else if (i > 0 && i - dp[i - 1] - 1 >= 0 &&
                 s[i - dp[i - 1] - 1] == '(') {
        dp[i] = (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) +
                dp[i - 1] + 2;
      }

      if (dp[i] > max_length) {
        max_length = dp[i];
        start_index = i - max_length + 1;
      }
    }
  }

  int getMaxLength() { return max_length; }
  int getStartIndex() { return start_index; }

private:
  std::string s;
  int max_length, start_index;
};

int main() {
  srand((unsigned)time(NULL));
  int test_num = 10; // 测试点个�?
  for (int index = 1; index <= test_num; index++) {
    std::string input_file = "input" + std::to_string(index) + ".txt";
    std::string output_file = "output" + std::to_string(index) + ".txt";
    std::ofstream fin(input_file);
    std::ofstream fout(output_file);

    int length;
    if (index <= test_num * 0.2) {
      length = rand() % 11 + 10;
    } else if (index <= test_num * 0.4) {
      length = rand() % 51 + 50;
    } else if (index <= test_num * 0.6) {
      length = rand() % 1001 + 9000;
    } else {
      length = 100000;
    }

    std::string str;

    for (int i = 0; i < length; i++) {
      // �?50%的测试数据中，在�?1/10段，尝试生成较长的合法字符串
      // 随着生成的进行，生成'('的概率从2/3衰减�?1/3
      if (i > length / 10 && index % 2 == 0) {
        if (rand() % 100 <
            33 + 33 * ((length * 9 / 10) - i) / (length * 9 / 10)) {
          str += '(';
        } else {
          str += ')';
        }
        continue;
      }
      // 其余测试点随机生�?
      // 生成')'的概率略大于'('�?51�?50�?
      if (rand() % 101 < 50) {
        str += '(';
      } else {
        str += ')';
      }
    }
    fin << str << std::endl;
    Solution solution(str);
    solution.slove();
    fout << solution.getMaxLength() << ' ' << solution.getStartIndex()
         << std::endl;

    fin.close();
    fout.close();
  }
  return 0;
}
