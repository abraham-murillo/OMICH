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

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  lli n;
  while (cin >> n) {
    cout << (isPrime(n) ? "Si" : "No") << '\n';
  }

  return 0;
}