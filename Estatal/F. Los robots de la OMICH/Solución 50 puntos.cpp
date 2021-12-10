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

  int cuenta[2] = {0, 0};
  for (int pos = 0; pos < n; pos++) {
    string x;
    cin >> x;

    for (int i = 0; i < s.size(); i++) {
      cuenta[pos] += veSuNombre(s, i, x);
    }
  }

  if (cuenta[0] == cuenta[1]) {
    cout << "2\n1 2\n";
  } else {
    cout << "1\n";
    cout << (cuenta[0] > cuenta[1] ? "1" : "2") << '\n';
  }

  return 0;
}
