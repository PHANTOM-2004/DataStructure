#include <cstring>
#include <iostream>

static const int INIT_SIZE = 10;
class String {
  friend std::ostream &operator<<(std::ostream &os, const String &str);

public:
  String(void);
  String(const char *data, int length);
  String(const char *data);
  String(const String &from); // 1 复制构造
  ~String();

  inline size_t size(void) const { return m_length; }
  inline bool empty(void) const { return m_length == 0; }

  bool operator==(const String &other) const;
  bool operator!=(const String &other) const { return !(*this == other); }
  String operator+(const String &other);
  String operator=(const String &other);
  const char &operator[](const int &index) const;
  void push_back(const char &c);
  void clear(void);

protected:
  void copy(const char *data, size_t length);

private:
  char *m_data;
  size_t m_length;
  size_t m_capacity = 0;
};

void String::clear(void) {
  if (m_data == nullptr)
    return;
  delete[] m_data;
  m_data = nullptr;
  m_length = 0;
}

void String::copy(const char *data, size_t length) {
  clear();
  m_data = new char[length];
  memcpy(m_data, data, sizeof(char) * length);
  m_length = length;
  m_capacity = length;
}

String::String(void) {
  m_data = nullptr;
  m_length = 0;
}

String::String(const char *data, int length) {
  m_data = nullptr;
  m_length = 0;
  copy(data, length);
}

String::String(const char *data) {
  m_data = nullptr;
  m_length = 0;
  copy(data, strlen(data));
}

String::String(const String &from) {
  m_data = nullptr;
  m_length = 0;
  if (from.m_data != m_data)
    copy(from.m_data, from.size());
}

String::~String() { clear(); }

const char &String::operator[](const int &index) const { return m_data[index]; }

bool String::operator==(const String &from) const {
  if (this->m_length != from.m_length)
    return false;
  for (size_t i = 0; i < m_length; i++) {
    if (from[i] != m_data[i]) {
      return false;
    }
  }
  return true;
}

String String::operator+(const String &other) {
  if (other.empty())
    return *this;
  if (m_length == 0)
    return other;
  String result;
  result.m_length = this->m_length + other.size();
  result.m_capacity = result.size();
  result.m_data = new char[result.size()];
  memcpy(result.m_data, m_data, result.size() * sizeof(char));
  memcpy(result.m_data + m_length, other.m_data, other.size());
  return result;
}

String String::operator=(const String &other) {
  if (&other != this) {
    copy(other.m_data, other.size());
  }
  return *this;
}

void String::push_back(const char &c) {
  if (m_capacity > m_length) {
    m_data[m_length++] = c;
    return;
  }
  m_capacity = m_capacity ? 2 * m_capacity : INIT_SIZE;
  const char *const former = m_data;
  m_data = new char[m_capacity];
  memcpy(m_data, former, sizeof(char) * m_length);
  delete[] former;
  m_data[m_length++] = c;
}

std::ostream &operator<<(std::ostream &os, const String &T) {
  for (size_t i = 0; i < T.size(); i++) {
    os << T[i];
  }
  return os;
}

int main() {
  String S1;
  String S2("s87552qqqqq");
  String S3("asd888sdsd999", 8);
  String S4(S2);
  S4 = S4;
  std::cout << S1 << '\n';
  std::cout << S2 << '\n';
  std::cout << S3 << '\n';
  std::cout << S4 << '\n';
  std::cout << "-----------\n";
  std::cout << S1 + S3 << '\n';
  S1.push_back('Q');
  std::cout << S1 << '\n';
  S2.push_back('A');
  std::cout << S2 << '\n';
  std::cout << "_________________\n";
  for (int i = 0; i < 100; i++) {
    S1.push_back('0' + i % 10);
    std::cout << S1 << '\n';
  }
  std::cout << S1 + S2 << '\n';
  return 0;
}