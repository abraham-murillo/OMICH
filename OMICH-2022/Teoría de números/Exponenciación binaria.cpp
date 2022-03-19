#include "debug.h"
#include <bits/stdc++.h>
using namespace std;

using lli = long long;

// base^pot
lli fpow(lli base, int pot) {
  if (pot == 0) {
    return 1LL;
  }
  if (pot == 1) {
    return base;
  }

  if (pot % 2 == 0) {
    lli mitad = fpow(base, pot / 2);
    // 2^50 = 2^25 * 2^25
    // base^(pot/2) * base^(pot/2) = base^pot
    return mitad * mitad;
  } else {
    // 2^51 = 2^50 * 2^1
    // base^(pot-1) * base^1 = base^pot
    return fpow(base, pot - 1) * base;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cout << fixed << setprecision(0) << pow(2, 50) << '\n';
  cout << fpow(2, 50) << '\n';

  return 0;
}
