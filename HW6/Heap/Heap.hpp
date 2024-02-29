
namespace Heap {

using rank = int;

template <typename T>
class HeapBuild {
 public:
  static rank percolateDown(T* const elem, const rank start, const rank n);
  static void heapify(T* const elem, const rank n);

 protected:
  static constexpr rank Parent(const rank x) { return (x - 1) / 2; }
  static constexpr rank LChild(const rank x) { return 2 * x + 1; }
  static constexpr rank RChild(const rank x) { return 2 * x + 2; }
  static constexpr rank IsRoot(const rank x) { return x <= 0; }
  static constexpr bool InHeap(const rank x, const rank n) {
    return x >= 0 && x < n;
  }
  static constexpr rank Greater(const T* const elem, const rank left,
                                const rank right) {
    return elem[left] < elem[right] ? right : left;
  }
  static constexpr bool HasLChild(const rank x, const int n) {
    return InHeap(LChild(x), n);
  }
  static constexpr bool HasRChild(const rank x, const int n) {
    return InHeap(RChild(x), n);
  }
  static rank maxIn3(const T* const elem, const rank x, const T& target,
                     const int n) {
    if (HasRChild(x, n)) {
      const rank maxChild = Greater(elem, LChild(x), RChild(x));
      return target > elem[maxChild] ? x : maxChild;
    } else if (HasLChild(x, n)) {
      return target > elem[LChild(x)] ? x : LChild(x);
    } else {
      return x;  // target itself
    }
  }
};

template <typename T>
rank HeapBuild<T>::percolateDown(T* const elem, const rank start,
                                 const rank n) {
  int i = start, j = -1;
  const auto target = elem[start];
  while (i != (j = maxIn3(elem, i, target, n))) {
    elem[i] = elem[j];
    i = j;
  }
  elem[j] = target;
  return j;
}

template <typename T>
void HeapBuild<T>::heapify(T* const elem, const rank n) {
  for (int i = Parent(n - 1); InHeap(i, n); i--) {
    percolateDown(elem, i, n);
  }
}

}  // namespace Heap
