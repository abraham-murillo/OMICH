#include "Bucket.h"
#include <bits/stdc++.h>
using namespace std;

int cubo[1005];
void inicio(int N, int M[]) {
  for (int i = 0; i < N; i++) {
    cubo[M[i]]++;
  }
}

int pregunta(int x) {
  return cubo[x];
}