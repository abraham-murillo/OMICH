#include "primo.h"
#include <bits/stdc++.h>
using namespace std;

// Main
//	int primo(int posicion)

const int N = 1e7 + 5;

bitset<N> isPrime;
vector<int> primes;

int busca(int n) {
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i <= n; i++)
    if (isPrime[i]) {
      primes.emplace_back(i);
      for (int j = i + i; j <= n; j += i)
        isPrime[j] = false;
    }

  int lo = 0, hi = primes.size() - 1;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;

    if (primo(mid) == primes[mid])
      lo = mid + 1;
    else
      hi = mid;
  }

  return primes[lo];
}