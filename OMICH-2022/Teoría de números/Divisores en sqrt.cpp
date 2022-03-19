#include "debug.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> divisores(int n) {
  vector<int> s;

  // Versión 1. Revisar n números
  // ¿Se puede hacer más rápido? ¿cómo?
  // Versión 2. Revisar sqrt(n) números
  for (int d = 1; 1LL * d * d <= n; d++)
    if (n % d == 0) {
      s.push_back(d);
      s.push_back(n / d);
    }

  return s;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  // 12
  // {1, 2, 3, 4, 6, 12}
  // x = 1, n / x = 12
  // x = 2, n / x = 6
  // x = 3, n / x = 4
  // x = 4, n / x = 3
  debug(divisores(12));

  // 9
  // {1, 3, 9}
  // x = 1, n / x = 9
  // x = 3, n / x = 3
  debug(divisores(9));

  // 13
  // {1, 13}
  debug(divisores(13));

  // 24
  // {1, 2, 3, 4, 6, 8, 12, 24}
  debug(divisores(24));

  return 0;
}
