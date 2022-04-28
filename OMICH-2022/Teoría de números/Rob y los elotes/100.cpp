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
using vi = vector<int>;

lli gcd(lli a, lli b) {
  return b ? gcd(b, a % b) : a;
}

lli lcm(lli a, lli b) {
  return a / gcd(a, b) * b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n;
  while (cin >> n) {

    vector<lli> days;
    fore (i, 0, n) {
      lli first, k;
      cin >> first >> k;
      days.push_back(first + k);
    }

    lli when = 0;
    for (int d : days) {
      if (when == 0)
        when = d;
      else
        when = lcm(when, d);
    }

    assert(when < 1e18);

    cout << when << '\n';
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