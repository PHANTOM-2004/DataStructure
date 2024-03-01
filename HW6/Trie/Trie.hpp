#include <array>
#include <string>
#include <vector>

class Trie {
  static constexpr int CHARACTER_NUMBER = 26;

public:
  Trie(const int capacity = 30) {
    buffer.reserve(capacity * 4);
    expand();
  };
  bool insert(const std::string &s);
  bool find(const std::string &s) const;
  int size() const { return _size; }
  bool operator[](const std::string &s) const { return find(s); }

protected:
  void expand() { buffer.emplace_back(); }
  struct TrieNode {
    friend Trie;
    int &operator[](const int index) { return child[index]; }
    int operator[](const int index) const { return child[index]; }

  private:
    std::array<int, CHARACTER_NUMBER> child{};
    int node_count = 0;
  };
  std::vector<TrieNode> buffer;
  int tot = 0;
  int _size = 0;
};