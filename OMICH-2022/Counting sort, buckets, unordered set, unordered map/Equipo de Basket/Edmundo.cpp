#include <bits/stdc++.h>
//#include "debug.h"
#define fore(i, l, r) for (long long i = (l); i < (r); i++)
#define ll long long
using namespace std;

int main() {
  ll nj, nje, e = 0, ma = 0, ju = 0, c = 0;
  cin >> nj >> nje;

  map<ll, ll> alturas;
  ll jugadores[nj];
  deque<ll> dq;
  fore (i, 0, nj) {
    cin >> jugadores[i];
  }

  fore (i, 0, nj) {
    ju++;
    dq.push_front(jugadores[i]);
    alturas[jugadores[i]]++;
    if (alturas[jugadores[i]] > 1)
      ma++;

    if (ma > 0) {
      while (alturas[jugadores[i]] != alturas[dq.back()]) {
        alturas[dq.back()]--;
        dq.pop_back();
        ju--;
      }
      alturas[dq.back()]--;
      dq.pop_back();
      ju--;
      ma--;
    }

    if (ju > nje) {
      ju--;
      alturas[dq.back()]--;
      dq.pop_back();
    }

    if (ju == nje)
      e++;
  }
  cout << e;
}