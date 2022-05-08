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

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n;
  while (cin >> n) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      auto it = lower_bound(v.begin(), v.end(), x);
      if (it != v.end())
        *it = x;
      else
        v.push_back(x);
    }

    cout << v.size() << '\n';
  }

  return 0;
}