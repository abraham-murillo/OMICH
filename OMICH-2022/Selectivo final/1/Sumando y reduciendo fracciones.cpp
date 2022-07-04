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

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll abajo = 1;
ll arriba = 0;
vector<ll> down;
vector<ll> up;

int main() {
  ll a, b, cont = 0;
  while (cin >> a >> b) {
    cont++;
    down.push_back(b);
    up.push_back(a);
    abajo *= b;
  }
  debug(abajo);
  fore (i, 0, cont) {
    arriba += (abajo / down[i]) * up[i];
  }
  debug(arriba);
  ll div = gcd(arriba, abajo);
  cout << arriba / div << " / " << abajo / div;
}