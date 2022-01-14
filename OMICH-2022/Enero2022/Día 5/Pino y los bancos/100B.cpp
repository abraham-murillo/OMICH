#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = (l); i < (r); i++)

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...)
#endif

const int N = 1e4 + 5;

vector<int> in[N], out[N];
int color[N];
map<string, int> toInt;
vector<string> toStr;
map<int, int> idk;
int n, q;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n >> q;
  fore (i, 0, n) {
    int x;
    string tmp;
    cin >> x;
    cin.ignore();
    getline(cin, tmp);

    if (!toInt.count(tmp)) {
      toInt[tmp] = toInt.size();
      toStr.push_back(tmp);
    }

    int k = toInt[tmp];
    idk[x] = k;
  }

  debug(idk);

  map<int, pair<int, int>> range;
  for (auto [x, i] : idk) {
    if (!range.count(i))
      range[i] = {x, x};
    else
      range[i].second = x;
  }

  // Suponiendo que no se pueden overlapear
  for (auto it : range) {
    auto [l, r] = it.second;
    in[l].push_back(it.first);
    out[r].push_back(it.first);
  }

  memset(color, -1, sizeof(color));
  set<int> alive;
  fore (pos, 0, N) {
    for (int id : in[pos])
      alive.insert(id);

    assert(alive.size() <= 1);
    if (alive.size()) {
      color[pos] = *alive.begin();
    }

    for (int id : out[pos])
      alive.erase(id);
  }

  while (q--) {
    int x;
    cin >> x;

    if (color[x] == -1) {
      cout << "N/A\n";
    } else {
      cout << toStr[color[x]] << '\n';
    }
  }

  return 0;
}
