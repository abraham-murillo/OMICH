#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n;
  cin >> n;

  if (n > 1) {
    cout << "-1\n";
    return 0;
  }

  string a;
  cin >> a;

  long long cost = 0, pos = 0;
  for (char c : a) {
    cost += min(abs(c - 'a' - pos), 26 - abs(c - 'a' - pos));
    pos = c - 'a';
  }

  cout << cost << '\n';

  return 0;
}