#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define fore(i, a, z) for (int i = a; i < z; i++)
#define endl '\n'
#define ll long long
using namespace std;
set<ll> nums;

void mult(ll n) {
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      nums.insert(i);
      nums.insert(n / i);
    }
  }
}

int main() {
  ll n;
  cin >> n;
  mult(n);
  for (auto i : nums) {
    cout << i << " ";
  }
}