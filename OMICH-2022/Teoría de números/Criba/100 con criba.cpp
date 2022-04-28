#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int N = 1e6 + 5;
bitset<N> isPrime;

int main() {
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  fore (i, 2, N)
    if (isPrime[i]) {
      for (int j = i + i; j < N; j += i)
        isPrime[j] = false;
    }

  int k, x;
  cin >> k;
  while (k--) {
    cin >> x;
    if (isPrime[x]) {
      cout << "Si" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }

  return 0;
}