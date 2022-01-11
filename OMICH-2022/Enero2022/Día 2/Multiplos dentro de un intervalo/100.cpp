#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int a, b;
  while (cin >> a >> b) {
    fore (i, a, b + 1) {
      if (i % a == 0) {
        cout << i << " ";
      }
    }
    cout << '\n';
  }

  return 0;
}