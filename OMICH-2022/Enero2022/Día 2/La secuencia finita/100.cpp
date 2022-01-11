#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n;
  while (cin >> n) {
    vector<int> ans;

    while (n > 1) {
      ans.push_back(n);
      if (n % 2 == 0)
        n /= 2;
      else
        n = n * 3 + 1;
    }
    ans.push_back(1);

    cout << ans.size() << '\n';
    for (int x : ans)
      cout << x << " ";
    cout << '\n';
  }

  return 0;
}