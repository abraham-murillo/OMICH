#include <bits/stdc++.h>
using namespace std;

using lli = long long;

struct Dsu {
  vector<int> par;
  int n;

  Dsu() {}
  Dsu(int n) : par(n + 1) {
    iota(par.begin(), par.end(), 0);
  }

  int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
  }

  bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
      par[u] = v;
      return true;
    }
    return false;
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }
};

Dsu dsu[105];
bool vis[105];
int n, m, q;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> m;

  while (m--) {
    int u, v, color;
    cin >> u >> v >> color;

    if (!vis[color]) {
      vis[color] = true;
      dsu[color] = Dsu(n);
    }

    dsu[color].unite(u, v);
  }

  cin >> q;

  while (q--) {
    int u, v;
    cin >> u >> v;

    bool any = false;
    for (int color = 1; color <= 100; color++)
      if (vis[color] && dsu[color].same(u, v)) {
        cout << color << " ";
        any = true;
      }

    if (!any) {
      cout << "*";
    }

    cout << '\n';
  }

  return 0;
}