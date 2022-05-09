#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using lli = long long;

const int N = 75;
lli mem[N][N][2];
int n, k;

lli dp(int pos, int bricks, bool lastWasBomb) {
  if (bricks > k)
    return 0;
  if (pos == n)
    return bricks == k;

  lli& ans = mem[pos][bricks][lastWasBomb];
  if (ans == -1) {
    ans = 0;
    if (lastWasBomb) {
      // place another bomb
      ans += dp(pos + 1, bricks, 1);
      // just continue
      ans += dp(pos + 1, bricks, 0);
    } else {
      // place another bomb
      ans += dp(pos + 1, bricks, 1);
      // meh
      ans += dp(pos + 1, bricks + 1, 0);
    }
  }

  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int q;
  cin >> q;
  fore (i, 0, q) {
    memset(mem, -1, sizeof(mem));
    cin >> n >> k;
    cout << dp(0, 0, 0) << '\n';
  }

  return 0;
}