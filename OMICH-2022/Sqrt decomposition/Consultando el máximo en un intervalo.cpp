#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using ld = long double;
using lli = long long;
using ii = pair<int, int>;

const int N = 1e6 + 5;
const int MOD = 1e6;
const int B = 1000;
int a[N];
int mxBlock[B + 5];
int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int aa, b, c, d;
  cin >> n >> aa >> b >> c >> d;

  // Genero la lista
  fore (i, 1, N) {
    if (i == 1) {
      a[i] = d;
    } else {
      a[i] = 1LL * a[i - 1] * a[i - 1] % MOD * aa % MOD;
      (a[i] += 1LL * a[i - 1] * b % MOD) %= MOD;
      (a[i] += c) %= MOD;
    }

    // Agregarlo al bloque
    mxBlock[i / B] = max(mxBlock[i / B], a[i]);
  }

  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;

    int mx = a[l];
    while (l <= r) {
      if (l % B == 0 && l + B - 1 <= r) {
        // Inicia un bloque nuevo
        // Si tomo todo el bloque alcanza a entrar la pregunta
        mx = max(mx, mxBlock[l / B]);
        l += B;
      } else {
        // Lo respondo de manera individual
        mx = max(mx, a[l]);
        l++;
      }
    }

    cout << mx << '\n';
  }

  return 0;
}

/* Please, check the following:
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * write down your ideas
 * DON'T get stuck on ONE APPROACH!
 * ASK for HELP from your TEAMMATES
 */