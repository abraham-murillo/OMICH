#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int main() {

  int n = 0, c = 0;
  cin >> n;

  string a;
  fore (i, 0, n) {
    cin >> a;

    if (a == "F")
      c += 2;
    else if (a == "DL" || a == "DL")
      c += 4;
    else if (a == "L" || a == "R")
      c = 0;
  }

  cout << c << '\n';

  return 0;
}