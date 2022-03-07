#include "Bucket.h"
#include <map>
using namespace std;

// red-black tree
// [key, value]

map<int, int> bucket;

void inicio(int N, int M[]) {
  // FIXME
  for (int i = 0; i < N; i++) {
    bucket[M[i]]++;
  }
}

int pregunta(int x) {
  return bucket[x];
}