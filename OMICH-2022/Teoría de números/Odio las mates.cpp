#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int funEsPrimo(int n) {
  // O(sqrt(n))
  // No hay ningún primo que sea par aparte del 2
  int cnt = 0;
  if (n % 2 == 0 && n != 2)
    return false;
  for (int d = 3; 1LL * d * d <= n; d += 2) {
    cnt++;
    if (n % d == 0) {
      break;
    }
  }
  return cnt;
}

const int N = 1000005;
bool esPrimo[N];

int criba(int n) {
  int cnt = 0;
  // Todos los números son primos
  fore (i, 0, n + 1)
    esPrimo[i] = true;

  esPrimo[0] = esPrimo[1] = 0;
  // O(n * log(log(n)))
  // O(3 * n) :D
  for (int i = 2; i <= n; i++) {
    if (esPrimo[i]) {
      for (int j = i + i; j <= n; j += i) {
        esPrimo[j] = false;
        cnt++;
      }
    }
  }

  return cnt;
}

int cribaConFunEsPrimo(int n) {
  int cnt = 0;
  for (int i = 0; i <= n; i++) {
    cnt += funEsPrimo(i);
  }
  return cnt;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  // 1e6 números, ver si es primo o no
  // 1e6 * sqrt(1e6) aprox

  fore (n, N - 50, N) {
    // ¿Cómo saber la complejidad si no quiero hacer matemáticas?
    int x = criba(n);
    debug(n, x, double(x) / double(n));
  }

  for (int n : {100, int(1e5), int(1e6)}) {
    int chido = criba(n);
    int malo = cribaConFunEsPrimo(n);
    debug(n, chido, malo, 100 * double(chido) / double(malo));
  }

  return 0;
}