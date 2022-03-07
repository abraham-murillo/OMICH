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

  if (a[0] + a[1] == obj) {
    cout << "SI" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  
  return 0;
}