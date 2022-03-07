#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = (l); i < (r); i++)

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...)
#endif

const int C = 1e5 + 5, N = 1005;

map<int, int> primeraPos;
map<int, int> cnt;
int a[N];
int n, c;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> c;

  fore (i, 0, n) {
    cin >> a[i];
    cnt[a[i]]++;
    if (!primeraPos.count(a[i])) {
      primeraPos[a[i]] = i;
    }
  }

  sort(a, a + n, [&](int x, int y) {
    if (cnt[x] != cnt[y])
      return cnt[x] > cnt[y];
    return primeraPos[x] < primeraPos[y];
  });

  fore (i, 0, n) {
    cout << a[i] << " ";
  }
  cout << '\n';

  return 0;
}