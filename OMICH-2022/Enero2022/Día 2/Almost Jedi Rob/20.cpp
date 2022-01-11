#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v;
  for (int i = 0; i < n; i++) {
    string op;
    cin >> op;

    if (op == "ADD") {
      int x;
      cin >> x;
      v.push_back(x);
    } else if (op == "POP") {
      v.pop_back();
    }
  }

  for (auto e : v)
    cout << e << " ";
  cout << '\n';

  return 0;
}