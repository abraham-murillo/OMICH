#include "AdivinaElNumero.h"

#include <bits/stdc++.h>
using namespace std;

// Main
//	long long pista(long long x)

map<long long, int> mem;

int pistaConMemoria(long long x) {
  if (!mem.count(x)) {
    mem[x] = pista(x);
  }
  return mem[x];
}

void adivina(long long a, long long b) {
  while (a < b) {
    long long mid = (a + b) / 2;

    int now = pistaConMemoria(mid);

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