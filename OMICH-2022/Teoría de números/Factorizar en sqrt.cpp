#include "debug.h"
#include <bits/stdc++.h>
using namespace std;

struct Factor {
  int num;
  int pot;

  friend ostream& operator<<(ostream& os, const Factor& f) {
    // return os << "(num: " << f.num << ", pot: " << f.pot << ")";
    return os << f.num << "^" << f.pot;
  }
};

vector<Factor> factorizacion(int n) {
  vector<Factor> fac;

  // Versión 1. Probar todos los divisores impares y el 2, revisar que el divisor sea primo
  // Versión 2. No revisamos si d es primo
  // debug(n);
  for (int d = 2; n > 1; d++) {
    if (n % d == 0) {
      // debug(d);
      fac.push_back({d, 0});
      while (n % d == 0) {
        fac.back().pot++;
        n /= d;
      }
      // debug(n, fac.back());
    }

    if (d != 2)
      d++;
  }

  return fac;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  // 12 = 2 * 2 * 3
  // 12 = 2^2 *3
  // factorizacion(12);

  // 30 = 2 * 3 * 5
  // 30 = 6 * 5

  // 85 = 5 * 17

  // 1105 = 5^1 * 13^1 * 17^1
  // factorizacion(1105);

  // 24 = 2^3 * 3^1
  // 24 = 2 * 2 * 2 * 3

  factorizacion(999983); // revisar si es primo antes de factorizar, esPrimo(n) => O(sqrt(n))

  debug(factorizacion(3010560)); // O(sqrt(n))

  return 0;
}