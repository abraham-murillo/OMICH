#include "debug.h"
#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int N = 1e6 + 5;
int factor[N];

void factorizeSieve() {
  iota(factor, factor + N, 0);
  for (int i = 2; i * i < N; i++)
    if (factor[i] == i)
      for (int j = i * i; j < N; j += i)
        factor[j] = i;
}

map<int, int> factorize(int n) {
  map<int, int> cnt;
  while (n > 1) {
    cnt[factor[n]]++;
    n /= factor[n];
  }
  return cnt;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  factorizeSieve();

  int tc;
  cin >> tc;

  int num;
  while (tc--) {
    cin >> num;

    auto fac = factorize(num);
    debug(fac);

    int cnt[2] = {0, 0};
    for (auto [p, k] : fac)
      cnt[k % 2]++;
    debug(cnt);

    if (cnt[0] == cnt[1])
      cout << "Especial\n";
    else if (cnt[0] > cnt[1])
      cout << "Par\n";
    else
      cout << "Impar\n";
  }

  return 0;
}
