#include "AdivinaElNumero.h"

#include <bits/stdc++.h>
using namespace std;

// Main
//	long long pista(long long x)

void adivina(long long a, long long b) {
  while (a < b) {
    long long mid = (a + b) / 2LL;
    int now = pista(mid);

    if (now == 0) {
      return;
    }

    if (now == -1) {
      b = mid - 1;
    } else {
      a = mid + 1;
    }
  }
  pista(a);
}