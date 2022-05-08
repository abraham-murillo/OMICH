#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using ld = long double;
using lli = long long;
using ii = pair<int, int>;

const int N = 101;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int mat[N][N];
int n, m;

bool valid(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

void vertical(char d) {
  int start = (d == 'N' ? 0 : n - 1);
  int delta = (d == 'N' ? +1 : -1);
  for (int c = 0; c < m; c++) {
    vector<int> val;
    for (int r = start; valid(r, c); r += delta) {
      if (mat[r][c] > 0)
        val.emplace_back(mat[r][c]);
      mat[r][c] = 0;
    }

    int pos = start;
    int last = 0;
    for (int x : val) {
      if (last && x == last) {
        mat[pos - delta][c] += x;
        last = 0;
      } else {
        mat[pos][c] = x;
        last = x;
        pos += delta;
      }
    }
  }
}

void horizontal(char d) {
  int start = (d == 'E' ? m - 1 : 0);
  int delta = (d == 'E' ? -1 : +1);
  for (int r = 0; r < n; r++) {
    vector<int> val;
    for (int c = start; valid(r, c); c += delta) {
      if (mat[r][c] > 0)
        val.emplace_back(mat[r][c]);
      mat[r][c] = 0;
    }

    int pos = start;
    int last = 0;
    for (int x : val) {
      if (last && x == last) {
        mat[r][pos - delta] += x;
        last = 0;
      } else {
        mat[r][pos] = x;
        last = x;
        pos += delta;
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> n >> m) {
    fore (r, 0, n)
      fore (c, 0, m) {
        cin >> mat[r][c];
      }

    string dir;
    cin >> dir;
    for (char d : dir) {
      if (d == 'N' || d == 'S') {
        vertical(d);
      } else {
        horizontal(d);
      }
    }

    fore (r, 0, n) {
      int mx = 0;
      fore (c, 0, m)
        mx = max(mx, mat[r][c]);

      if (mx > 0)
        cout << mx << '\n';
    }
  }

  return 0;
}