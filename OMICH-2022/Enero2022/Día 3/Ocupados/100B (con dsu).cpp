#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

struct Dsu {
  vector<int> par, tot;

  Dsu(int n = 1) : par(n + 1), tot(n + 1, 1) {
    iota(par.begin(), par.end(), 0);
  }

  int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
  }

  void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
      par[v] = u;
      tot[u] += tot[v];
    }
  }
};

const int N = 1e6 + 5;
int a[N];
int order[N];
int n;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  fore (i, 0, n) {
    cin >> a[i];
    order[i] = i;
  }

  stable_sort(order, order + n, [&](int i, int j) {
    return a[i] < a[j];
  });

  int mn = 1e9;
  fore (it, 0, 2) {
    Dsu dsu(n);
    fore (i, 0, n)
      if (order[i] != i) {
        dsu.unite(order[i], i);
      }

    int swaps = 0;
    fore (i, 0, n)
      if (dsu.find(i) == i) {
        swaps += dsu.tot[i] - 1;
      }

    mn = min(mn, swaps);

    reverse(order, order + n);
  }

  cout << mn << '\n';

  return 0;
}