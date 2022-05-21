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
const int Q = N;

vector<int> in[N], out[N];
stack<int> last[Q];
lli ans[Q];
lli pref[N];
lli a[N];
int n, q;

lli query(int l, int r) {
  return pref[r] - pref[l - 1];
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  fore (i, 1, n + 1) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  cin >> q;
  fore (i, 0, q) {
    int k;
    cin >> k;
    while (k--) {
      int l, r;
      cin >> l >> r;
      in[l].push_back(i);
      out[r].push_back(i);
    }
  }

  fore (pos, 1, n + 1) {
    // Agrego paréntesis que abren
    for (int i : in[pos]) {
      last[i].push(pos);
    }

    // Cerrar paréntesis
    for (int i : out[pos]) {
      if (last[i].size() == 1) {
        // Tengo que resolver la query
        ans[i] += query(last[i].top(), pos);
      }
      last[i].pop();
    }
  }

  fore (i, 0, q) {
    cout << ans[i] << '\n';
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