#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (auto i = (l) - ((l) > (r)); i != (r) - ((l) > (r)); i += 1 - 2 * ((l) > (r)))
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define pb push_back

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int N = 101;

int area[N][N][N];
int mat[N][N];
int n, m, k;

int query(int color, int r1, int c1, int r2, int c2) {
  return area[color][r2][c2] - area[color][r1 - 1][c2] - area[color][r2][c1 - 1] + area[color][r1 - 1][c1 - 1];
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> m >> k;
  fore (r, 0, n)
    fore (c, 0, m) {
      cin >> mat[r][c];
      area[mat[r][c]][r][c]++;
    }

  fore (i, 0, k + 1)
    fore (r, 0, n)
      fore (c, 0, m) {
        area[i][r][c] += area[i][r - 1][c];
        area[i][r][c] += area[i][r][c - 1];
        area[i][r][c] -= area[i][r - 1][c - 1];
      }

  int mx = min(n, m);
  while (mx >= 2) {
    int fullArea = mx * mx;
    for (int r = 0; r + mx - 1 < n; r++)
      for (int c = 0; c + mx - 1 < m; c++)
        if (query(mat[r][c], r, c, r + mx - 1, c + mx - 1) == fullArea) {
          goto MaxFound;
        }

    mx--;
  }

MaxFound:;

  cout << mx << " ";

  bitset<N> vis;
  int fullArea = mx * mx;
  int cnt = 0;
  for (int r = 0; r + mx - 1 < n; r++)
    for (int c = 0; c + mx - 1 < m; c++) {
      debug(r, c, mat[r][c]);
      if (query(mat[r][c], r, c, r + mx - 1, c + mx - 1) == fullArea) {
        cnt++;
        vis[mat[r][c]] = 1;
      }
    }

  cout << cnt << " " << vis.count() << '\n';

  return 0;
}

/* Please, check the following:
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * write down your ideas
 * DON'T get stuck on ONE APPROACH!
 * ASK for HELP from your TEAMMATES
 */