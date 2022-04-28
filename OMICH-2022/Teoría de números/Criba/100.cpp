#include <iostream>
using namespace std;

bool isPrime(int x) {
  if (x == 1)
    return false;
  for (int i = 2; 1LL * i * i <= x; i++)
    if (x % i == 0)
      return false;
  return true;
}

int main() {
  int k, x;
  cin >> k;
  while (k--) {
    cin >> x;
    if (isPrime(x)) {
      cout << "Si" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}
