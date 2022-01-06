#include <bits/stdc++.h>
using namespace std;

string a[10];
int n;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  long long mn = 1e18;
  do {
    long long cost = 0, pos = 0;

    for (int i = 0; i < n; i++)
      for (char c : a[i]) {
        cost += min(abs(c - 'a' - pos), 26 - abs(c - 'a' - pos));
        pos = c - 'a';
      }

    mn = min(mn, cost);
  } while (next_permutation(a, a + n));

  cout << mn << '\n';

  return 0;
}