#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int main() {

  string n, m, n2 = "", m2 = "";
  int n3, m3, n4, m4;
  cin >> n >> m;
  n4 = stoi(n);
  m4 = stoi(m);
  for (int i = 0; i < n.size(); i++) {
    n2 += n[n.size() - i - 1];
    m2 += m[m.size() - i - 1];
  }
  n3 = stoi(n2);
  m3 = stoi(m2);
  cout << n4 << " + " << m4 << " = " << n4 + m4 << '\n';
  cout << n3 << " + " << m3 << " = " << n3 + m3 << '\n';

  return 0;
}