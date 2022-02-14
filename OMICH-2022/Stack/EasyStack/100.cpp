#include <bits/stdc++.h>
using namespace std;

// Tan trivial que sólo es hacer lo que nos piden

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  stack<int> s;
  int t;
  cin >> t;

  int op, x;
  while (t--) {
    cin >> op;

    if (op == 1) {
      cin >> x;
      s.push(x);
    } else if (op == 2) {
      if (!s.empty())
        s.pop();
    } else {
      if (s.empty()) {
        cout << "Empty!\n";
      } else {
        cout << s.top() << '\n';
      }
    }
  }

  return 0;
}