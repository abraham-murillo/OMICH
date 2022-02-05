#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

const int N = 1e5 + 5;

int a[N];
int n, t;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> n >> t) {
    // Si hacen while (leer entrada) NO se olviden de resetear sus variables globales
    fore (i, 0, n) {
      cin >> a[i];
    }

    int mx = 0;
    int sum = 0;
    for (int l = 0, r = 0; l < n; l++) {
      // Mientras Job aún pueda leer el siguiente libro lo lee
      while (r < n && sum + a[r] <= t) {
        sum += a[r];
        r++;
      }

      debug("Rango", l, r - 1, sum, "tomando", r - l);

      // Calculamos el máximo
      mx = max(mx, r - l);

      // Quitamos el libro de la izquierda
      sum -= a[l];
    }

    cout << mx << '\n';
  }

  return 0;
}