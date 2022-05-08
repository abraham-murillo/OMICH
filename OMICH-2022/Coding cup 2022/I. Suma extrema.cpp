#include <iostream>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;

  unsigned long long sumA = (a * (a + 1)) / 2;
  unsigned long long sumB = (b * (b + 1)) / 2;
  cout << sumA + sumB << '\n';

  return 0;
}