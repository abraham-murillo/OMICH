#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using ull = unsigned long long;

const ull INF = numeric_limits<ull>::max();
vector<ull> fib = {0, 1};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // 2^64 no cabe en un long long, el número máximo es 2^63-1
  // Usamos unsigned long long, algo importante de este tipo de datos es el overflow, si sumamos algo más grande que 2^64, este vuelve a empezar desde
  // 0, es decir, 2^64+1 es lo mismo que 0, usando esto podemos intentar generar "500" fibonaccis, sabemos que cuando fib(i) < fib(i-1) + fib(i-2),
  // este hizo overflow y ya tenemos todos los posibles fibonaccis hasta 2^64.

  fore (i, 2, 500) {
    fib.emplace_back(fib[i - 1] + fib[i - 2]);
    if (fib.back() < fib[i - 1]) {
      fib.pop_back();
      break;
    }
  }

  // Para resolver una pregunta, basta con hacer una binaria para ver si existe y con lower_bound encontrar su posición.
  ull x;
  while (cin >> x) {
    if (binary_search(fib.begin(), fib.end(), x)) {
      cout << lower_bound(fib.begin(), fib.end(), x) - fib.begin() << '\n';
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}