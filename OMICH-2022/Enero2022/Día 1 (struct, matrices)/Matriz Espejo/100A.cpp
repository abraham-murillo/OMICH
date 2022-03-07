#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

const int N = 105;
int a[N][N];
int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> m >> n;

  fore (i, 0, m)
    fore (j, 0, n) {
      cin >> a[i][j];
    }

  fore (i, 0, m) {
    fore (j, 0, n) {
      cout << a[i][n - 1 - j] << " ";
    }
    cout << '\n';
  }

  return 0;
}
