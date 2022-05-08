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

  lli k;
  cin >> k;
  lli sum = 0;
  for (lli pw = 1; pw <= k; pw *= 2LL) {
    sum += k / pw;
  }

  cout << sum << '\n';

  return 0;
}