#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

void error(int pos) {
  cout << "ERROR L" << pos << '\n';
}

unordered_map<string, int> val;
unordered_map<string, string> link;

// Esto es dsu te pasaste @Rob :C, ojalá no de TLE xd
string original(string& s) {
  if (link[s] == s)
    return s;
  return link[s] = original(link[s]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  string op, x, y;
  int pos = 1;
  while (cin >> op >> x) {
    if (op == "VAR") {
      // debug(op, x);
      if (val.find(x) != val.end() || link.find(x) != link.end()) {
        error(pos);
      } else {
        val[x] = 0;
        link[x] = x;
      }
    } else if (op == "REF") {
      cin >> y;

      // debug(op, x, y);
      bool xAsVal = val.find(x) != val.end();
      bool yAsVal = val.find(y) != val.end();
      bool xAsLink = link.find(x) != link.end();
      bool yAsLink = link.find(y) != link.end();
      // debug(xAsVal, xAsLink);
      // debug(yAsVal, yAsLink);

      if ((!xAsLink && yAsVal) || (!xAsLink && yAsLink)) {
        link[x] = original(y);
      } else {
        error(pos);
      }
    } else if (op == "INC") {
      // debug(op, x);

      if (link.find(x) == link.end()) {
        error(pos);
      } else {
        val[original(x)]++;
      }
    } else if (op == "PRINT") {
      // debug(op, x);

      if (link.find(x) == link.end()) {
        error(pos);
      } else {
        cout << val[original(x)] << '\n';
      }
    }

    pos++;
    // debug("");
  }

  return 0;
}