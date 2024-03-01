#include "Trie.hpp"
#include <cctype>

bool Trie::insert(const std::string &s) {
  int p = 0;
  _size++;
  for (const auto iter : s) {
    const int id = std::tolower(iter) - 'a';
    if (buffer[p][id] == 0) {
      expand();
      buffer[p][id] = ++tot;
    }
    p = buffer[p][id];
  }
  buffer[p].node_count++;
  return true;
}

bool Trie::find(const std::string &s) const {
  int p = 0;
  for (const auto iter : s) {
    const int id = std::tolower(iter) - 'a';
    const auto &node = buffer[p];
    if (node[id] == 0)
      return false;
    p = node[id];
  }
  return buffer[p].node_count;
}