#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

// Criba de factorización

const int N = 105;
int factor[N];

void cribaFactorizacion(int n) {
  fore (i, 0, N) {
    factor[i] = i;
  }
  for (int i = 2; 1LL * i * i <= n; i++) {
    if (factor[i] == i) {
      for (int j = 1LL * i * i; j <= n; j += i) {
        factor[j] = i;
      }
    }
  }
}

map<int, int> factorizar(int n) {
  map<int, int> cnt;
  while (n > 1) {
    cnt[factor[n]]++;
    n /= factor[n];
  }
  return cnt;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  // 2 : {2^1}
  // 8: {2^3}
  // 15: {3^1 * 5^1}
  // 24: {2^3 * 3^1}
  // ...

  cribaFactorizacion(100);

  debug(factorizar(2));
  debug(factorizar(8));
  debug(factorizar(15));
  debug(factorizar(24));
  debug(factorizar(21));

  return 0;
}