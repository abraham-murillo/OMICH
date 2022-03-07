#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (auto i = (l) - ((l) > (r)); i != (r) - ((l) > (r)); i += 1 - 2 * ((l) > (r)))
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define pb push_back

#ifdef LOCAL
const int N = 10;
#include "debug.h"
#else
const int N = 1e5 + 5;
#define debug(...) 
#endif

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <class T>
bool umax(T& a, T b) {
  return (a = max(a, b)) == b;
}


template <class T>
bool umin(T& a, T b) {
  return (a = min(a, b)) == b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  // solve the problem here D:
  int n, q; cin >> n >> q;
  map<string, int> left;
  map<string, int> right;
  fore (i, 0, n) {
    int x;
    string address;
    cin >> x;
    cin.ignore();
    getline(cin, address);
    debug(x, address);
    if (left.count(address) == 0) {
      left[address] = x;
    }
    if (right.count(address) == 0) {
      right[address] = x;
    }

    umin(left[address], x);
    umax(right[address], x);
  }

  // debug(left, right);

  vector<pair<int, string>> mx(10005, make_pair(-1, "?"));

  for (auto [address, val] : left) {
    mx[val] = make_pair(right[address], address);
  }

  fore (i, 1, 1e4 + 3) {
    pair<int, string> trash = make_pair(-1, "?");
    if (mx[i] == trash) {
      mx[i] = mx[i - 1];
    }
  }
  debug(mx);

  while (q--) {
    int x;
    cin >> x;
    pair<int, string> trash = make_pair(-1, "?");
    cout << (mx[x] == trash || mx[x].first < x ? "N/A" : mx[x].s) << '\n';
  }

  return 0;
}
