#include <iostream>

class Sort_Method {
  int *arr;
  int num;

public:
  Sort_Method(const int n) {
    arr = new int[n];
    for (num = 0; num < n; num++) {
      arr[num] = rand();
    }
  }
  ~Sort_Method() { delete[] arr; }
  void print() {
    for (int i = 0; i < num; i++)
      std::cout << arr[i] << " \n"[i == num - 1];
  }
  void select_sort();
  void bubble_sort();
  void insert_sort();
};

void Sort_Method::select_sort() {
  for (int i = 0; i < num; i++) {
    for (int j = i + 1; j < num; j++) {
      if (arr[j] < arr[i])
        std::swap(arr[j], arr[i]);
    }
  }
}

void Sort_Method::bubble_sort() {
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num - 1 - i; j++) {
      if (arr[j] > arr[j + 1])
        std::swap(arr[j], arr[j + 1]);
    }
  }
}

void Sort_Method::insert_sort() {
  for (int i = 1; i < num; i++) {
    int now = arr[i], j = 0;
    for (j = i - 1; j >= 0; j--) {
      if (arr[j] <= now)
        break;
      arr[j + 1] = arr[j];
    }
    j++;
    arr[j] = now;
  }
}

int main() {
  Sort_Method S(10);
  S.print();
  S.select_sort();
  S.print();
  std::cout << "___________________\n";
  /*---------------*/
  Sort_Method T(10);
  T.print();
  T.bubble_sort();
  T.print();
  std::cout << "___________________\n";
  /*---------------*/
  Sort_Method N(10);
  N.print();
  N.insert_sort();
  N.print();
  std::cout << "___________________\n";
  return 0;
}
