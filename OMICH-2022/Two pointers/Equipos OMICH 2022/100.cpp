#include "debug.h"
#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int N = 2e5 + 5;

lli a[N];
int n;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> n) {
    fore (i, 0, n) {
      cin >> a[i];
    }
    a[n] = 2e9;

    // Ordenamos por su habilidad
    sort(a, a + n);

    // Con two-pointers juntamos en un mismo equipo siempre y cuando su diferencia sea menor o igual que 5
    int mx = 0;
    for (int l = 0, r = 0; l < n; l++) {
      while (r + 1 <= n && abs(a[l] - a[r + 1]) <= 5)
        r++;
      mx = max(mx, r - l + 1);
    }

    cout << mx << '\n';
  }

  return 0;
}