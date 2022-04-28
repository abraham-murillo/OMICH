#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int N = 1e6 + 5;
bitset<N> isPrime;
int sum[N];
int q;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  fore (i, 2, N) {
    sum[i] = sum[i - 1];

    if (isPrime[i]) {
      sum[i]++;
      for (int j = i + i; j < N; j += i)
        isPrime[j] = false;
    }
  }

  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    cout << sum[r] - sum[l - 1] << '\n';
  }

  return 0;
}