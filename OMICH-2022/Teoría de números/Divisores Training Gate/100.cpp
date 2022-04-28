#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  lli n;
  while (cin >> n, n != 0) {
    set<lli> divs;

    for (lli i = 1; i * i <= n; i++)
      if (n % i == 0) {
        divs.insert(i);
        divs.insert(n / i);
      }

    cout << divs.size() << '\n';
    for (auto x : divs)
      cout << x << " ";
    cout << '\n';
  }

  return 0;
}