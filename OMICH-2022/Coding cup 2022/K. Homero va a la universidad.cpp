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

const int N = 1e5 + 5;
int inv[N];
string s;
int n, q;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    cin >> s;
    n = s.size();

    int wrong = 0;
    for (int i = 0; i < n; i++) {
      inv[i] = n - 1 - i;
      if (i <= inv[i] && s[i] != s[inv[i]]) {
        wrong++;
      }
    }

    cin >> q;
    int pos;
    char ch;
    while (q--) {
      cin >> pos >> ch;

      pos--;

      bool lastWrong = s[pos] != s[inv[pos]];
      s[pos] = ch;
      bool curWrong = s[pos] != s[inv[pos]];

      if (lastWrong) {
        if (curWrong) {
          // no pasa nada
        } else {
          wrong--;
        }
      } else {
        if (curWrong) {
          wrong++;
        } else {
          // no pasa nada
        }
      }

      cout << (wrong == 0 ? "Si" : "No") << '\n';
    }

    if (tc > 0)
      cout << '\n';
  }

  return 0;
}