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

const int N = 1e7 + 5;
bitset<N> isPrime;
vector<lli> sum[10];
vector<int> primes[10];

void sieve() {
  isPrime.set();
  isPrime[0] = 0;
  isPrime[1] = 1;
  for (int i = 2; i * i < N; ++i)
    if (isPrime[i])
      for (int j = i * i; j < N; j += i)
        isPrime[j] = 0;

  fore (i, 1, N)
    if (isPrime[i]) {
      if (sum[i % 10].empty()) {
        sum[i % 10].push_back(0);
        primes[i % 10].push_back(-1);
      }

      sum[i % 10].push_back(i + sum[i % 10].back());
      primes[i % 10].push_back(i);
    }
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  sieve();

  int tc;
  cin >> tc;

  while (tc--) {
    int n, e;
    cin >> n >> e;

    int last = e % 10;
    int pos = upper_bound(primes[last].begin(), primes[last].end(), e) - primes[last].begin();

    debug(pos);
    // debug(primes[last]);

    if (sum[last].size() > pos + n - 1) {
      cout << sum[last][pos + n - 1] - sum[last][pos - 1] << '\n';
    } else {
      cout << "IMPOSIBLE\n";
    }
  }

  return 0;
}