#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 
#endif

// te mantiene un conjunto de datos ordenadas por un orden dado

struct orden {
  bool operator ()(int x, int y) {
    return !(x < y);
  }
};

priority_queue<int, vector<int>, orden> pq, pq2;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  debug(pq.empty()); // v
  pq.push(10);
  pq.push(5);
  pq.push(8);
  pq.push(7);
  pq.push(4);
  debug(pq.empty()); // f

  // 4, 5, 7, 8, 10
  debug(pq.size());
  pq.pop(); // // 5, 7, 8, 10
  debug(pq.size());
  pq.push(6); // 5, 6, 7, 8, 10
  pq.pop(); // 6, 7, 8, 10
  cout << pq.top() << '\n';

  return 0;
}