#include <bits/stdc++.h>
using namespace std;

bool veSuNombre(string& s, int i, string& x) {
  // Regresa true sólo si 'x' existe completamente dentro de 's' empezando en la posición 'i'
  for (int j = 0; j < x.size(); j++) {
    if (i + j >= s.size())
      return false;
    if (x[j] != s[i + j])
      return false;
  }
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  string s;
  cin >> s;

  int n;
  cin >> n;

  int mx = 0;
  vector<int> quien;
  for (int pos = 0; pos < n; pos++) {
    string x;
    cin >> x;

    int cuenta = 0;
    for (int i = 0; i < s.size(); i++) {
      cuenta += veSuNombre(s, i, x);
    }

    if (cuenta > mx) {
      mx = cuenta;
      quien.clear();
    }
    if (cuenta == mx) {
      quien.push_back(pos);
    }
  }

  cout << quien.size() << '\n';
  for (int i : quien)
    cout << i + 1 << " ";
  cout << '\n';

  return 0;
}