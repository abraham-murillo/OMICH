#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

const int N = 105;
vector<int> divisores[N];

void cribaDivisores(int n) {
  for (int i = 1; i <= n; i++) {
    // Agarramos un número i, y pasamos por todos sus MULTIPLOS
    // j es MULTIPLO de i, por lo tanto, i es DIVISOR de j
    for (int j = i; j <= n; j += i) {
      divisores[j].push_back(i);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  // 2 : {1, 2}
  // 8: {1, 2, 4, 8}
  // 15: {1, 3, 5, 15}
  // ...

  cribaDivisores(100);

  fore (i, 1, 10) {
    debug(i, divisores[i]);
  }

  debug(100, divisores[100]);

  return 0;
}