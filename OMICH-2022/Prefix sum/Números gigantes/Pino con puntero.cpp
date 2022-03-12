#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (auto i = (l) - ((l) > (r)); i != (r) - ((l) > (r)); i += 1 - 2 * ((l) > (r)))
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define pb push_back

#ifdef LOCAL
const int N = 10;
#include "debug.h"
#else
const int N = 1e5 + 5;
#define debug(...)
#endif

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

// 1 2 3 4
// 1 3 6 10

// 1 2 3 6 200 250 a
// 1 3 6 12 212 462 prefix_sum

// x = 0

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  // solve the problem here D:
  int n;
  cin >> n;
  vector<lli> a(n);
  vector<lli> prefix_sum(n);
  fore (i, 0, n) {
    cin >> a[i];
  }

  sort(a.begin(), a.end()); // trivial

  // Clase de Rob
  prefix_sum[0] = a[0];
  fore (i, 1, n) {
    prefix_sum[i] = prefix_sum[i - 1] + a[i];
  }

  debug(a);
  debug(prefix_sum);
  int q;
  cin >> q;

  vector<pair<lli, int>> x(q);
  vector<lli> res(q);
  fore (i, 0, q) {
    cin >> x[i].first;
    x[i].second = i;
  }

  sort(x.begin(), x.end());
  // 0 2000 100 3
  // 0 3 100 2000

  int idx = 0; //
  lli suma = 0;
  fore (i, 0, q) {
    while (idx < n && a[idx] <= x[i].first) {
      suma += a[idx];
      idx++;
    }

    res[x[i].second] = suma;
  }

  fore (i, 0, q) {
    cout << res[i] << '\n';
  }
  // a y x, ordenados

  return 0;
}