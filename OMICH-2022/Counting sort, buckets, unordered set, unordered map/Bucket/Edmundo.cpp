#include "Bucket.h"
#include <vector>
using namespace std;
vector<int> v(100, 0);
int ma = 0;
void inicio(int N, int M[]) {
  for (int i = 0; i < N; i++) {
    if (ma < M[i])
      ma = M[i];
    v[M[i]]++;
  }
}

int pregunta(int x) {
  return v[x];
}