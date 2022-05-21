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
vector<int> in[N], out[N];
int f[N], v[N];
int n, a, b;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> a >> b;
  fore (i, 0, n) {
    cin >> f[i] >> v[i];
    in[f[i]].push_back(i);
    out[v[i] + 1].push_back(i);
  }

  set<pair<int, int>> s;
  for (int x = 1; x <= b; x++) {
    // agregar esa fruta al set
    for (int i : in[x]) {
      s.insert({f[i], i});
    }
    // quito las frutas del set
    for (int i : out[x]) {
      s.erase({f[i], i});
    }

    if (a <= x && x <= b) {
      // me interesa saber la info aquí
      if (s.empty()) {
        cout << "-1 -1 0\n";
      } else {
        int last = s.rbegin()->first;
        int first = s.begin()->first;

        cout << x - last << " ";
        cout << x - first << " ";
        cout << s.size() << '\n';
      }
    }
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