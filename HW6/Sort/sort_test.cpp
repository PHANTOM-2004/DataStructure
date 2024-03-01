#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <vector>

#include "sort_func.hpp"

constexpr int SEED = 29;

static void generate_sequence(std::vector<int> &t, const int n,
                              const bool reverse = false,
                              const bool sorted = false) {
  t.resize(n);
  if (sorted) {
    for (int i = 0; i < n; i++)
      t[i] = i;
  } else if (!reverse)
    for (int i = 0; i < n; i++)
      t[i] = rand();
  else
    for (int i = 0; i < n; i++)
      t[i] = n - i - 1;
}

class SortTest {
  using func_type = std::function<void(int *, int, int)>;
  func_type sort_func;

public:
  SortTest(func_type sort) : sort_func(sort) {}
  double runtest(const int n, const bool reverse = false,
                 const bool sorted = false) {
    srand(SEED);
    std::vector<int> test;
    generate_sequence(test, n, reverse, sorted);
    using namespace std::chrono;
    const auto begin = high_resolution_clock::now();
    sort_func(test.data(), 0, n);
    const auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - begin);
    double res = 0;
    std::cout << "Size : " << n
              << " Time : " << (res = duration.count() / 1000.0) << " ms"
              << std::endl;
    return res;
  }
};

static void basic_test(std::function<void(int *, int, int)> sort) {
  static auto print = [](const int elem) { std::cout << elem << ' '; };
  std::vector<int> test;
  srand(SEED);
  constexpr int N = 40;
  test.reserve(N);
  for (int i = 0; i < N; i++) {
    test.push_back(rand() % (3 * N));
  }

  std::for_each(test.begin(), test.end(), print);
  std::cout << '\n';
  sort(test.data(), 0, test.size());
  std::for_each(test.begin(), test.end(), print);
  std::cout << '\n';
}

template <typename T>
static void stdSort(T *const elem, const int low, const int high) {
  std::sort(elem + low, elem + high);
}

int main() {
  using namespace sort_impl;
  if constexpr (0) {
    std::cout << "bubbleSort" << std::endl;
    basic_test(bubbleSort<int>);
    std::cout << "selectionSort" << std::endl;
    basic_test(selectionSort<int>);
    std::cout << "insertionSort" << std::endl;
    basic_test(insertionSort<int>);
    std::cout << "mergeSort" << std::endl;
    basic_test(mergeSort<int>);
    std::cout << "heapSort" << std::endl;
    basic_test(heapSort<int>);
    std::cout << "quickSort" << std::endl;
    basic_test(quickSort<int>);
    std::cout << "shellSort" << std::endl;
    basic_test(shellSort<int>);
    std::cout.flush();
  }

  auto test = [](const int N, const bool reverse = false,
                 const bool sorted = false) {
    std::cout << "------------Test Begin-------------\n";
    std::cout << "stdSort" << std::endl;
    SortTest T0(stdSort<int>);
    T0.runtest(N, reverse, sorted);

    std::cout << "MySort" << std::endl;

    std::cout << "heapSort" << std::endl;
    SortTest T2(heapSort<int>);
    T2.runtest(N, reverse, sorted);

    std::cout << "mergeSort" << std::endl;
    SortTest T3(mergeSort<int>);
    T3.runtest(N, reverse, sorted);

    std::cout << "quickSort" << std::endl;
    SortTest T4(quickSort<int>);
    T4.runtest(N, reverse, sorted);

    std::cout << "shellSort" << std::endl;
    SortTest T5(shellSort<int>);
    T5.runtest(N, reverse, sorted);

    std::cout << "insertionSort" << std::endl;
    SortTest T6(insertionSort<int>);
    T6.runtest(N, reverse, sorted);

    std::cout << "selectionSort" << std::endl;
    SortTest T7(selectionSort<int>);
    T7.runtest(N, reverse, sorted);

    std::cout << "bubbleSort" << std::endl;
    SortTest T1(bubbleSort<int>);
    T1.runtest(N, reverse, sorted);
    std::cout << "------------Test End-------------\n";
  };
  if constexpr (0) {
    constexpr int testcase = 3;
    for (int i = 0; i < testcase; i++) {
      test(rand());
    }
    for (int i = 0; i < testcase; i++) {
      test(rand() % 200);
    }
  }
  if constexpr (1) {
    test(10000, true);        // 10k逆序
    test(10000, false, true); // 10k正序
  }
  if constexpr (1) {
    // 10，100，1K，10K，100K，1M
    test(10);
    test(100);
    test(1000);
    test(10000);
    test(100000);
    test(1000000);
  }
}