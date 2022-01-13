#include <bits/stdc++.h>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int n; cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);

  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    cout << binary_search(a, a + n, x);
    if (i != m - 1) {
      cout << ' ';
    }
  }
  cout << '\n';

  return 0;
}