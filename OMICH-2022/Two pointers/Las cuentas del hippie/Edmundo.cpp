#include <bits/stdc++.h>
//#include "debug.h"
#define fore(i, l, r) for (long long i = (l); i < (r); i++)
#define ll long long
using namespace std;
int main() {
  ll nn, nc, r, f = 1e9, n = 0, desp = 0, cont = 0;
  cin >> nn >> nc;
  int c[nc];
  n = nc;
  deque<int> tom;
  fore (i, 0, n) {
    cin >> c[i];
  }
  fore (i, 0, n + nn) {
    r = i;
    if (i >= n)
      r = i - n;
    tom.push_front(c[r]);
    if (c[r] == 0)
      cont++;
    else
      desp++;
    while (cont > nn) {
      while (tom.back() == 0) {
        tom.pop_back();
        cont--;
      }
      while (tom.back() == 1) {
        tom.pop_back();
        desp--;
      }
    }
    while (tom.back() == 1) {
      tom.pop_back();
      desp--;
    }
    if (cont >= nn && f > desp)
      f = desp;
    // cout<<r<<": "<<f<<"\n";
  }
  cout << f;
}