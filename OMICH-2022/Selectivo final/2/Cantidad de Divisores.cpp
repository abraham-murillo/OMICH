#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define fore(i, a, z) for (int i = a; i < z; i++)
#define endl '\n'

using namespace std;

int div(int n) {
  set<int> div;
  div.insert(1);
  div.insert(n);
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      div.insert(i);
      div.insert(n / i);
    }
  }
  return div.size();
}

int main() {
  int n;
  cin >> n;

  int num;
  while (n--) {
    cin >> num;
    cout << div(num) << endl;
  }
}