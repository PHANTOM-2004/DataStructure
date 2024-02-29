#include <algorithm>

#include "Heap/Heap.hpp"

namespace sort_impl {

template <typename T>
void bubbleSort(T *const elem, const int low, const int high) {
  if (high - low < 2)
    return;
  bool sorted = false;
  int n = high;
  while (!sorted) {
    sorted = true;
    for (int i = low; i < n - 1; i++) {
      if (elem[i] > elem[i + 1]) {
        sorted = false;
        std::swap(elem[i], elem[i + 1]);
      }
    }
    n--;
  }
}

template <typename T>
void selectionSort(T *const elem, const int low, const int high) {
  if (high - low < 2)
    return;
  auto find_max = [elem](const int low, const int high) {
    auto max_elem = elem[low];
    int max_pos = 0;
    for (int i = low; i < high; i++) {
      if (elem[i] > max_elem) {
        max_elem = elem[i];
        max_pos = i;
      }
    }
    return max_pos;
  };

  int n = high;
  while (--n > low) {
    std::swap(elem[n], elem[find_max(low, n)]);
  }
}

template <typename T>
void insertionSort(T *const elem, const int low, const int high) {
  if (high - low < 2)
    return;
  for (int i = low + 1; i < high; i++) {
    const auto target = elem[i];
    auto pos = std::upper_bound(elem + low, elem + i, target);
    for (int j = i; j > pos - elem; j--) {
      elem[j] = elem[j - 1];
    }
    *pos = target;
  }
}

template <typename T>
static void merge(T *const elem, const int low, const int mid, const int high) {
  const int la = mid - low, lb = high - mid;
  T *const A = new T[la];
  T *const B = elem + mid;
  for (int i = 0; i < la; i++)
    A[i] = elem[i + low];

  int i = 0, j = 0, tot = low;
  while (i < la && j < lb) {
    if (A[i] <= B[j]) {
      elem[tot++] = A[i++];
    } else {
      elem[tot++] = B[j++];
    }
  }
  while (i < la)
    elem[tot++] = A[i++];
  delete[] A;
}

template <typename T>
void mergeSort(T *const elem, const int low, const int high) {
  if (high - low < 2)
    return;
  const auto mid = (high + low) / 2;
  mergeSort(elem, low, mid);
  mergeSort(elem, mid, high);
  merge(elem, low, mid, high);
}

template <typename T>
void heapSort(T *const elem, const int low, const int high) {
  using namespace Heap;
  T *const A = elem + low;
  rank size = high - low;
  HeapBuild<T>::heapify(A, size);
  while (--size) {
    std::swap(A[0], A[size]);
    HeapBuild<T>::percolateDown(elem, 0, size);
  }
}

template <typename T> static int partition(T *const elem, int low, int high) {
  std::swap(elem[low], elem[low + rand() % (high - low)]);
  const auto pivot = elem[low];
  while (low < high) {
    do
      high--;
    while (low < high && pivot <= elem[high]);
    if (low < high)
      elem[low] = elem[high];
    do
      low++;
    while (low < high && elem[low] < pivot);
    if (low < high)
      elem[high] = elem[low];
  }
  elem[high] = pivot;
  return high;
}

template <typename T>
void quickSort(T *const elem, const int low, const int high) {
  if (high - low < 2)
    return;
  const auto mid = partition(elem, low, high);
  quickSort(elem, low, mid);
  quickSort(elem, mid + 1, high);
}

} // namespace sort_impl
