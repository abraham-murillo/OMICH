#include <bits/stdc++.h>
#define fore(i, l, r) for (long i = (l); i < (r); i++)

using namespace std;

const int N = 1e5 + 5;

long long sum[N];
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  fore (i, 1, n + 1) {
    long long x;
    cin >> x;
    sum[i] = sum[i - 1] + x;
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << "\n";
  }

  return 0;
}