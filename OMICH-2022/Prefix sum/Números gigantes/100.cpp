#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (long i = (l); i < (r); i++)

const int N = 1e6 + 10;
using lli = long long;
lli sum[N];

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n;
  cin >> n;
  vector<lli> a(n);
  fore (i, 0, n)
    cin >> a[i];

  vector<lli> b = a;
  sort(b.begin(), b.end());
  b.push_back(1e18);
  b.erase(unique(b.begin(), b.end()), b.end());

  for (auto& x : a) {
    int pos = lower_bound(b.begin(), b.end(), x) - b.begin();
    sum[pos] += x;
  }

  fore (i, 1, b.size()) {
    sum[i] += sum[i - 1];
  }

  int q;
  cin >> q;
  while (q--) {
    lli x;
    cin >> x;

    int pos = upper_bound(b.begin(), b.end(), x) - b.begin() - 1;

    cout << (pos == -1 ? 0LL : sum[pos]) << '\n';
  }

  return 0;
}