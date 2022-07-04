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
vector<int> pos;
int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;

  pos.pb(-1);
  pos.pb(int(1e9) + 1);
  fore (i, 0, n) {
    int p;
    char c;
    cin >> p >> c;

    if (c == 'B') {
      pos.pb(p);
    }
  }

  sort(all(pos));

  cin >> m;
  fore (i, 0, m) {
    int l, r;
    cin >> l >> r;

    int ll = lower_bound(all(pos), l) - pos.begin();
    int rr = upper_bound(all(pos), r) - pos.begin() - 1;

    cout << rr - ll + 1 << '\n';
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