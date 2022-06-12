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

const int N = 10005;
vector<int> graph[N];
bool vis[N];
int n, m;

void dfs(int u) {
  vis[u] = 1;

  for (int v : graph[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> m;
  fore (i, 0, m) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int ans = 0;
  fore (u, 1, n + 1) {
    if (!vis[u]) {
      dfs(u);
      ans++;
    }
  }

  cout << ans << '\n';

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