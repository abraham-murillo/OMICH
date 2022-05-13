#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct DSU {
  vector<int> parent;
  vector<int> size;
  int groups;

  DSU(int n) {
    parent.resize(n + 1);
    size.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);
    fill(size.begin(), size.end(), 1);
    groups = n;
  }

  void add() {
    parent.push_back(parent.size());
    size.push_back(1);
    groups++;
  }

  int find(int u) { return u == parent[u] ? u : parent[u] = find(parent[u]); }

  bool connected(int u, int v) { return find(u) == find(v); }

  void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;

    if (size[u] < size[v]) swap(u, v);
    parent[v] = u;
    size[u] += size[v];
    --groups;
  }
};

void solve(int t) {
    while (t--) {
        int n, m;
        cin >> n >> m;
        DSU dsu(n);
        while(m--) {
          int x, y;
          cin >> x >> y;
          dsu.unite(x, y);
        }
        cout << dsu.groups << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    solve(t);
    return 0;
}