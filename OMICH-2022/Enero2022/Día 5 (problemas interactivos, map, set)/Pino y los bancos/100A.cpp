#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...)
#endif

struct Cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
    return a.second < b.second;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;

  map<string, pair<int, int>> bankRanges;
  while (N--) {
    int code;
    string dir;
    cin >> code;
    cin.ignore();
    getline(cin, dir);
    if (bankRanges.count(dir))
      bankRanges[dir] = {min(bankRanges[dir].first, code), max(bankRanges[dir].second, code)};
    else
      bankRanges[dir] = {code, code};
  }

  map<pair<int, int>, string, Cmp> directions;
  for (auto const& [key, val] : bankRanges) {
    directions[val] = key;
  }
  debug(directions);

  auto isValid = [&](int x, pair<int, int> range) -> bool {
    return range.first <= x && x <= range.second;
  };

  while (Q--) {
    int code;
    cin >> code;

    auto it = directions.lower_bound({code, code});

    // Nos movemos para atrás unos 3, siempre y cuando haya uno
    for (int i = 0; i < 3 && prev(it) != directions.end(); i++)
      it--;

    // Revisamos los siguientes 6
    bool exists = false;
    for (int i = 0; i < 6 && it != directions.end(); i++) {
      if (isValid(code, it->first)) {
        cout << it->second << '\n';
        exists = true;
        break;
      }
      it++;
    }

    if (!exists) {
      cout << "N/A\n";
    }
  }

  return 0;
}