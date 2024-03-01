#include "Trie.hpp"
#include <iostream>

int main() {
  // 简单测试字典树正确性
  constexpr bool Trie_test = false;
  if constexpr (Trie_test) {
    Trie T;
    const std::string ins[] = {"absdasd", "asjkdgYsj",  "dodzfpodkjd",
                               "sss",     "absda",      "aaa",
                               "abc",     "abcbcbcbcbc"};
    for (const auto &iter : ins) {
      T.insert(iter);
      std::cout << T.size() << ' ';
    }
    std::cout << std::endl;
    for (const auto &iter : ins) {
      std::cout << "find : " << iter << '\n';
      std::cout << T.find(iter) << '\n';
    }
    for (const auto &iter : ins) {
      std::cout << "find : " << iter + "AMD" << '\n';
      std::cout << T.find(iter + "AMD") << '\n';
    }
    std::cout << T.size();
  }
}
