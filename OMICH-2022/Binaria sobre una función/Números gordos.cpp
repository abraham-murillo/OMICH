#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define fore(i, l, r) for (int i = l; i < r; i++)

// int <= 2e9
// long long <= 1e18

using lli = long long;

lli a, c;

int sumDig(lli n) {
  int sum = 0;
  // 12345678
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

bool gordo(lli n) {
  return n - sumDig(n) >= c;
}

lli bruta() {
  lli cantidadGordos = 0;
  fore (i, 1, a + 1) {
    cantidadGordos += gordo(i);
  }
  return cantidadGordos;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> a >> c;

  // 1          x    a a+1
  // 0000000000 111111

  // 1    a a+1
  // 000000 0

  // cantidad de números gordos
  // a-x

  lli inicio = 1, fin = a + 1;
  while (inicio + 1 < fin) {
    lli mid = (inicio + fin) / 2;

    if (gordo(mid)) {
      // 1     mid    a
      // 000011[1]111111
      fin = mid;
    } else {
      // 1     mid    a
      // 000000[0]000111111
      inicio = mid;
    }
  }

  debug(inicio, gordo(inicio)); // no lo es
  debug(fin, gordo(fin)); // podría serlo

  lli cantidadGordos = 0;

  if (fin == a + 1) {
    // gordo(a+1) sí sea, [1, a]
    // no hay gordos
  } else {
    cantidadGordos = a - inicio;
  }

  // nos echamos un padre nuestro y lo enviamos
  cout << cantidadGordos << '\n';

  // cout << bruta() << '\n';

  return 0;
}