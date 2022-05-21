#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using ld = long double;
using lli = long long;
using ii = pair<int, int>;

const int N = 1e5 + 5;
const int B = 317;

struct Block {
  set<int> s;

  int size() {
    return s.size();
  }

  int query(int pos) {
    for (int x : s) {
      if (pos == 1)
        return x;
      pos--;
    }
    return -1;
  }

  void kill(int x) {
    s.erase(x);
  }
};

Block block[B + 5];
string s[N];
int n, m;

int get(int pos) {
  int l = 0, r = n - 1;
  while (l <= r) {
    // ¿El soldado está en este bloque?
    if (pos <= block[l / B].size()) {
      return block[l / B].query(pos);
    }
    pos -= block[l / B].size();
    l += B;
  }
  return -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  fore (i, 0, n) {
    cin >> s[i];
    block[i / B].s.insert(i);
  }

  fore (i, 0, n) {
    debug(i, i / B, s[i]);
  }

  fore (b, 0, B + 5) {
    if (block[b].s.empty())
      continue;

    debug(b, block[b].s);
  }

  cin >> m;
  char op;
  int pos;
  while (m--) {
    cin >> op >> pos;

    debug(op, pos);

    if (op == 'P') {
      cout << s[get(pos)] << '\n';
    } else {
      // kill
      int who = get(pos);
      block[who / B].kill(who);
      debug(who, who / B, block[who / B].s);
    }
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