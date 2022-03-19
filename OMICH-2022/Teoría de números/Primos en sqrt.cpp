#include "debug.h"
#include <bits/stdc++.h>
using namespace std;

int cnt;

bool esPrimo(int n) {
  // No hay ningún primo que sea par aparte del 2
  if (n % 2 == 0 && n != 2)
    return false;

  // Tenemos 2 divisores que son {1, n}
  // Versión 1. Revisar n-2 números
  // Versión 2. Revisar (n-2)/2 números, ignorando todos los pares
  // ¿Hay forma de hacerlo mejor?
  // Versión 3. Revisar sqrt(n) números

  // y = sqrt(n)
  // y * y = n
  for (int d = 3; 1LL * d * d <= n; d += 2) {
    cnt++;
    if (n % d == 0) {
      // Tiene otro divisor, y ya no es primo
      return false;
    }
  }
  return true;
}

int main() {
  // 12 = sqrt(3)
  // 1, 2, 3, 4, 6, 12
  // n/x
  // x=1, n/1=12
  // x=2, n/2=6
  // x=3, n/3=4

  // 9 = sqrt(9)
  // 1, 3, 9

  cnt = 0;
  debug(esPrimo(999983));
  debug(cnt);

  return 0;
}