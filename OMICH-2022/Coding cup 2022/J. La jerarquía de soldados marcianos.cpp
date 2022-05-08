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
const int SQ = 320;

set<int> alive[SQ];
string s[N];
int n, q;

pair<int, int> query(int k) {
  for (int b = 0; b < SQ; b++) {
    if (k <= alive[b].size()) {
      debug(b, k);
      for (int x : alive[b]) {
        if (k == 1)
          return {x, b};
        k--;
      }
    }
    k -= alive[b].size();
  }

  return {-1, -1};
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  fore (i, 0, n) {
    cin >> s[i];
    alive[i / SQ].insert(i);
  }

  cin >> q;
  char op;
  int k;
  while (q--) {
    cin >> op >> k;

    auto [x, b] = query(k);

    if (op == 'P') {
      cout << s[x] << '\n';
    } else {
      alive[b].erase(x);
    }
  }

  return 0;
}