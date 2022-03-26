#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

// Criba de eratostenes
// Criba divisores
// Criba de factorización

bool funEsPrimo(int n) {
  // O(sqrt(n))
  // No hay ningún primo que sea par aparte del 2
  if (n % 2 == 0 && n != 2)
    return false;
  for (int d = 3; 1LL * d * d <= n; d += 2) {
    if (n % d == 0) {
      // Tiene otro divisor, y ya no es primo
      return false;
    }
  }
  return true;
}

const int N = 105;
bool esPrimo[N];

vector<int> criba(int n) {
  // Todos los números "son primos"
  fore (i, 0, n + 1)
    esPrimo[i] = true;

  // O(n * log(log(n)))
  esPrimo[0] = esPrimo[1] = 0;
  for (int i = 2; 1LL * i * i <= n; i++) {
    if (esPrimo[i]) {
      // Descartar todos los múltiplos
      for (int j = 1LL * i * i; j <= n; j += i) {
        esPrimo[j] = false;
      }
    }
  }

  vector<int> primos;
  for (int i = 2; i <= n; i++) {
    if (esPrimo[i]) {
      primos.push_back(i);
    }
  }
  return primos;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  // 1e6 números, ver si es primo o no
  // 1e6 * sqrt(1e6) aprox

  // Sabes si x es primo o no
  int x = 19;
  cout << (esPrimo[x] ? "Si" : "No") << '\n';

  return 0;
}