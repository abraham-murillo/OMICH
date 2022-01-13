#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...)
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  vector<int> a = {1, 2, 3, 4, 5};
  set<int> st = {8, 10, 5, 2, 4};

  int x = 5, y = 7;
  double pi = 3.1416, wtf = 1.234567;

  debug(a, st);
  debug(x, y, pi, wtf);
  debug("Soy noob", x, "y lo se", y);

  bool soyNoob = true;
  debug(soyNoob);

  return 0;
}