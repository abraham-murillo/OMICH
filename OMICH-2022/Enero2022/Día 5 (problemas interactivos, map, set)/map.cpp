#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 
#endif

// map
// [key, val]

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
    map<int, int> mp; // {{0, 7}}
    debug(mp);
    mp[0] = 7;
    mp[1] = 3;
    mp[3] = 7;
    mp[50] = 0;
    mp[100] = -1; 
    mp[-1] = 100000000;
    mp[39128490] = 813;
    mp[-28347] = 183;
    debug(mp);

    mp.count(2);
    debug(mp);
  return 0;
}