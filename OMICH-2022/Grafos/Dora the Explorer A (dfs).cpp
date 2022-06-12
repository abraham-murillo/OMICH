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

const int N = 55;
vector<ii> dir = {ii(0, -1), ii(0, 1), ii(1, 0), ii(-1, 0)};
char mat[N][N];
bool vis[N][N];
int n, m;

void dfs(int u) {
  vis[u] = 1;

  for (int v : graph[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j) {
  vis[i][j] = 1;

  fore (k, 0, 4) {
    int ni = i + dir[k].f;
    int nj = j + dir[k].s;

    if (!valid(ni, nj))
      continue; // posición inválida

    if (mat[ni][nj] == '*')
      continue; // hay una pared

    if (!vis[ni][nj])
      dfs(ni, nj);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> m;
  fore (i, 0, n)
    fore (j, 0, m) {
      cin >> mat[i][j];
    }

  ii start(-1, -1);
  fore (i, 0, n) {
    fore (j, 0, m) {
      if (mat[i][j] == '#') {
        start = {i, j};
        break;
      }
    }
    if (start.f != -1)
      break;
  }

  dfs(start.f, start.s);

  fore (i, 0, n) {
    fore (j, 0, m) {
      if (vis[i][j]) {
        cout << "#";
      } else {
        cout << mat[i][j];
      }
    }
    cout << '\n';
  }

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