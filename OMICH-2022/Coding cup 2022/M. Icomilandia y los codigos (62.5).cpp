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

bool isPalindrome(int x) {
  string s = to_string(x);
  for (int l = 0, r = s.size() - 1; l < r; l++, r--)
    if (s[l] != s[r])
      return 0;
  return 1;
}

const long long INF = 1e10;
vector<long long> v;

void dfs(string x) {
  long long num = x.size() ? stoll(x) : 0;
  if (num >= INF)
    return;

  v.push_back(num);

  for (char ch = '1'; ch <= '9'; ch++) {
    dfs(string(1, ch) + x + string(1, ch));
    dfs(string(1, ch) + "0" + x + "0" + string(1, ch));
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  dfs("");
  for (char ch = '0'; ch <= '9'; ch++) {
    dfs(string(1, ch));
  }

  sort(v.begin(), v.end());
  debug(v.size());

  int x, n;
  while (cin >> x >> n) {
    int pos = lower_bound(v.begin(), v.end(), x) - v.begin();

    if (v[pos] != x)
      pos--;

    pos += n;

    cout << v[pos] << '\n';
  }

  return 0;
}