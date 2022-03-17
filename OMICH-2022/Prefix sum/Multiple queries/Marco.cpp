#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, z) for (int i = a; i < z; i++)
#define ll long long
#define pp pair<long long, char>
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> arr(n);
  fore (i, 0, n) {
    cin >> arr[i];
  }
  vector<ll> prefix(n);
  prefix[0] = arr[0];
  fore (i, 1, n) {
    prefix[i] = prefix[i - 1] + arr[i];
  }
  // pregunta=q
  int q;
  cin >> q;
  while (q--) {
    stack<ll> pos;
    vector<pp> name;
    // sub-pregunta=qq;
    int qq;
    cin >> qq;
    while (qq--) {
      int x, y;
      cin >> x >> y;
      name.push_back({x, '('});
      name.push_back({y, ')'});
    }
    ll suma = 0;
    sort(name.begin(), name.end());
    int inicio = 0;
    for (auto& [key, value] : name) {
      if (pos.empty()) {
        inicio = key;
      }
      if (value == '(') {
        pos.push(key);
      } else if (!pos.empty()) {
        pos.pop();
      }
      if (pos.empty()) {
        inicio--;
        key -= 1;
        if (inicio == 0 || inicio == -1) {
          suma += prefix[key];
        } else {
          suma += prefix[key] - prefix[inicio - 1];
        }
      }
    }
    cout << suma << '\n';
  }
}