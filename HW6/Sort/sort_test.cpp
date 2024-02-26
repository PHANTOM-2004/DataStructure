#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

static void generate_sequence(std::vector<int> &t, const int n,
                              const bool reverse = false) {
  t.resize(n);
  if (!reverse)
    for (int i = 0; i < n; i++) t[i] = rand();
  else
    for (int i = 0; i < n; i++) t[i] = n - i - 1;
}

template <typename func_type>
class SortTest {
  func_type sort_func;

 public:
  SortTest(func_type T) : sort_func(T) {}
  double runtest(const int n, const bool reverse = false) {
    std::vector<int> test;
    generate_sequence(test, n, reverse);
    using namespace std::chrono;
    const auto begin = high_resolution_clock::now();
    sort_func(test, 0, n);
    const auto end = high_resolution_clock::now();
    auto duration = end - begin;
    double res = 0;
    std::cout << "Size : " << n
              << " Time : " << (res = duration.count() / 1000.0) << " ms"
              << std::endl;
    return res;
  }
};

int main() { std::vector<int> test; }