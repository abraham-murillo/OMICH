#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N];
int n, q;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cin >> q;
  int l, r;
  while (q--) {
    cin >> l >> r;

    int mx = 0, cnt = 0;
    for (int i = l; i <= r; i++) {
      if (a[i] > mx) {
        mx = a[i];
        cnt = 0;
      }
      if (a[i] == mx) {
        cnt++;
      }
    }

    cout << cnt << '\n';
  }

  return 0;
}