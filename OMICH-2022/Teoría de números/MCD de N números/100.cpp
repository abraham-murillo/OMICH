#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)
using lli = long long;

lli gcd(lli a, lli b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n;
  while (cin >> n) {
    lli ans = 0;
    fore (i, 0, n) {
      lli x;
      cin >> x;
      ans = gcd(ans, x);
    }

    cout << ans << '\n';
  }

  return 0;
}