#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using lli = long long;

const int N = 1e5 + 5;
int a[N];
int n, m;

bool can(lli x) {
  int cnt = 1;
  lli sum = 0;
  // La idea es intentar crear meses en donde de tal manera que nunca gaste más de x por mes, y la cantidad total de meses sea menor que m

  // - cnt es la cantidad de meses
  // - sum es lo que ha gastado en total en cada mes, no puede gastar más de x por mes
  fore (i, 0, n) {
    sum += a[i];
    if (sum > x) {
      sum = a[i];
      cnt++;
    }
  }

  debug(x, cnt);
  return cnt <= m;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> n >> m) {
    lli lo = 0, hi = 2e9;
    fore (i, 0, n) {
      cin >> a[i];
      lo = max<lli>(lo, a[i]);
    }

    // Tenemos que buscar la menor cantidad de dinero con el cual sobrevivir por mes
    while (lo + 1 < hi) {
      lli mid = (lo + hi) >> 1;
      if (can(mid))
        hi = mid;
      else
        lo = mid;
    }

    lli ans = hi;
    if (can(lo))
      ans = lo;

    cout << ans << '\n';
  }

  return 0;
}
