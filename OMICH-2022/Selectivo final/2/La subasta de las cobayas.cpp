#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define fore(i, a, z) for (int i = a; i < z; i++)
#define endl '\n'
#define ll long long

using namespace std;

int main() {
  int n;
  cin >> n;
  int first = 0, second = 0, win = 0;
  fore (i, 1, n + 1) {
    int num;
    cin >> num;
    if (num >= first + second) {
      second = first;
      first = num;
      win = i;
    }
  }
  cout << win;
}