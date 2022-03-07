#include "debug.h"
#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int N = 60005;
int c[N];
int n, k;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> k >> n;
  fore (i, 0, n) {
    cin >> c[i];
    // Duplicamos el arreglo y así "tenemos" un arreglo circular
    c[i + n] = c[i];
  }

  // 0 0 1 1 1 0 0 1| 0 0 1 1 1 0 0 1
  
  int black = 0;
  int waste = 1e9;
  for (int l = 0, r = 0; l <= n; l++) {
    while (r < 2 * n && black < k) {
      if (c[r] == 0)
        black++;
      r++;
    }

    int total = r - l;
    debug("Cut", l, r - 1, total - black);
    waste = min(waste, total - black);

    if (c[l] == 0)
      black--;
  }

  cout << waste << '\n';

  return 0;
}