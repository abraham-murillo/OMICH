#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

const int N = 1e5;
string s[N];
int n;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;

  fore (i, 0, n)
    cin >> s[i];

  string a, b;
  cin >> a >> b;

  int me = -1;
  fore (i, 0, n)
    if (s[i] == a) {
      me = i;
      break;
    }

  int mn = 1e9;
  fore (i, 0, n)
    if (s[i] == b) {
      mn = min(mn, (i - me + n) % n);
      mn = min(mn, (me - i + n) % n);
    }

  cout << mn << '\n';

  return 0;
}
