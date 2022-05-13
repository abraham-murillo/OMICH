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
        DSU dsu(m);
        vector<bool> usedLanguages(m+1);
        int personsWithNoLanguage = 0; 
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            if (k == 0) {
                ++personsWithNoLanguage;
                continue;
            }
            vector<int> languages(k);
            for (int j = 0; j < k; j++) {
                cin >> languages[j];
                usedLanguages[languages[j]] = true;
            }
            for (int j = 0; j < k - 1; j++) dsu.unite(languages[j], languages[j+1]);
        }
        for (int i = 1; i <= m; i++) if (!usedLanguages[i]) dsu.groups--;
        if (dsu.groups == 1 and personsWithNoLanguage == 0) {
            cout << "0" << endl;
        } else {
            cout << (max(0, dsu.groups - 1) + personsWithNoLanguage) << endl;
        }
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