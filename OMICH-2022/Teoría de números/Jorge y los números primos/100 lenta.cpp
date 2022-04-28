#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool isPrime(lli x) {
  if (x == 1)
    return false;
  for (lli i = 2; i * i <= x; i++)
    if (x % i == 0)
      return false;
  return true;
}

const int N = 1e6 + 5;
int sum[N];
int q;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  fore (i, 2, N)
    sum[i] = sum[i - 1] + isPrime(i);

  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    cout << sum[r] - sum[l - 1] << '\n';
  }

  return 0;
}