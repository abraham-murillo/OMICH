#include <bits/stdc++.h>
using namespace std;


int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n, obj; cin >> n >> obj;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    int x = obj - a[i];
    if (x != a[i] && binary_search(a, a + n, x) == true) {
      cout << "SI" << '\n';
      return 0;
    }
  }
  
  cout << "NO" << '\n';
  return 0;
}
