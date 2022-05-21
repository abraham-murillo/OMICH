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

const int N = 1e5 + 5;
const int B = 317;

struct Block {
  vector<int> arr;

  int query(int v) {
    // todos los que sean < v
    return lower_bound(arr.begin(), arr.end(), v) - arr.begin();
  }

  void build() {
    sort(arr.begin(), arr.end());
    arr.push_back(1e9);
  }
};

Block block[B + 5];
int a[N];
int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  fore (i, 1, n + 1) {
    cin >> a[i];

    block[i / B].arr.push_back(a[i]);
  }

  fore (b, 0, B + 5) {
    if (block[b].arr.empty())
      continue;

    block[b].build();
  }

  cin >> m;
  while (m--) {
    int l, r, v;
    cin >> l >> r >> v;

    l++;

    int ans = 0;
    while (l <= r) {
      if (l % B == 0 && l + B - 1 <= r) {
        // pregunto al bloque qué pex
        ans += block[l / B].query(v);
        l += B;
      } else {
        // pregunto individualmente
        ans += (a[l] < v);
        l++;
      }
    }

    cout << ans << '\n';
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