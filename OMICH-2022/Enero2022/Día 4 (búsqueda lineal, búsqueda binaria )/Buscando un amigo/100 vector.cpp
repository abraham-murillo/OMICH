#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

const int N = 1e5;
string s[N];
int n;

vector<int> getPos(string& x) {
  vector<int> pos;
  fore (i, 0, n)
    if (s[i] == x)
      pos.push_back(i);
  return pos;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;

  fore (i, 0, n)
    cin >> s[i];

  string a, b;
  cin >> a >> b;

  auto posA = getPos(a);
  auto posB = getPos(b);

  assert(posA.size() == 1);
  assert(posB.size() >= 1);

  int mn = 1e9;
  for (int i : posA)
    for (int j : posB) {
      mn = min(mn, (i - j + n) % n);
      mn = min(mn, (j - i + n) % n);
    }

  cout << mn << '\n';

  return 0;
}
