#include "debug.h"
#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int N = 1e5 + 5;
int a[N], t[N];
int n, k;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> k;
  fore (i, 0, n)
    cin >> a[i];

  int write = 0;
  fore (i, 0, n) {
    cin >> t[i];
    if (t[i] == 1)
      write += a[i];
  }

  int mx = 0;
  int awake = 0;
  for (int l = 0, r = 0; l + k <= n; l++) {
    while (r < n && r - l < k) {
      if (t[r]) {
        write -= a[r];
      }
      awake += a[r];
      r++;
    }

    debug(l, r - 1, write, awake);
    mx = max(mx, write + awake);

    if (t[l]) {
      write += a[l];
    }
    awake -= a[l];
  }

  cout << mx << '\n';

  return 0;
}