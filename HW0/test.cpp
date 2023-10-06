#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  float a[13] = {0};
  float sum = 0;
  for (int i = 0; i < 12; i++) {
    cin >> a[i];
    sum += a[i];
  }
  std::string S = "";
  S += 'a';
  cout << "гд" << setiosflags(ios::fixed) << setprecision(2) << sum / 12
       << endl;
  return 0;
}
