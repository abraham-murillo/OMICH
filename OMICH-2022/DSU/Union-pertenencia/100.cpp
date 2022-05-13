#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

struct DSU {
  vector<int> parent;
  vector<int> size;
  int groups;

  DSU(int n) {
    parent.resize(n);
    size.resize(n);
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

int main() { 
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  while (m--) {
    char op;
    cin >> op;
    int x, y;
    cin >> x >> y;
    if (op == 'U') {
      dsu.unite(x, y);
    } else {
      cout << dsu.connected(x, y) << endl;
    }
  }
  return 0;
}