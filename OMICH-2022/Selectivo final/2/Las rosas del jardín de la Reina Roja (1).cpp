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
#include "debug.h"
#else
#define debug(...)
#endif

using ld = long double;
using lli = long long;
using ii = pair<int, int>;

const int N = 1e5 + 5;
ii queries[N];
int pos[N];
char color[N];
int pref[2 * N];
int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;

  vector<int> compress;
  compress.emplace_back(-1);
  compress.emplace_back(int(1e9) + 1);

  fore (i, 0, n) {
    cin >> pos[i] >> color[i];
    if (color[i] == 'B')
      compress.emplace_back(pos[i]);
  }

  cin >> m;
  fore (i, 0, m) {
    int l, r;
    cin >> l >> r;
    queries[i] = {l, r};
    compress.emplace_back(l);
    compress.emplace_back(r);
  }

  sort(all(compress));
  compress.erase(unique(all(compress)), compress.end());

  auto where = [&](int x) {
    return lower_bound(all(compress), x) - compress.begin();
  };

  fore (i, 0, n) {
    if (color[i] == 'B')
      pref[where(pos[i])]++;
  }

  fore (p, 1, compress.size()) {
    pref[p] += pref[p - 1];
  }

  fore (i, 0, m) {
    int l = where(queries[i].f);
    int r = where(queries[i].s);
    cout << pref[r] - pref[l - 1] << '\n';
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