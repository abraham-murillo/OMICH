#include <bits/stdc++.h>
using namespace std;


int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  // solve the problem here D:
  int n, obj; cin >> n >> obj;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] + a[j] == obj) {
        cout << "SI" << '\n';
        return 0;
      }
    }
  }

  cout << "NO" << '\n';
  return 0;
}