#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

const int N = 1e6 + 5;
long long t, h[N];
int n;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> t >> n;

  fore (i, 0, n) {
    cin >> h[i];
  }

  int g = 0;
  fore (i, 0, n) {
    t -= h[i];
    g++;
    if (t <= 0) {
      break;
    }
  }

  cout << (t > 0 ? 0 : g) << '\n';

  return 0;
}