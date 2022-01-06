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

int cuenta[10];

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  string s;
  cin >> s;

  int n;
  cin >> n;

  int mx = 0;
  for (int pos = 0; pos < n; pos++) {
    string x;
    cin >> x;

    cuenta[pos] = 0;
    for (int i = 0; i < s.size(); i++) {
      cuenta += veSuNombre(s, i, x);
    }

    mx = max(mx, cuenta[pos]);
  }
  
  int cuantos = 0;
  for (int pos = 0; pos < n; pos++) {
    if (cuenta[pos] == mx)
       cuantos++;
  }

  cout << cuantos << '\n';
  for (int pos = 0; pos < n; pos++) {
    if (cuenta[pos] == mx)    
       cout << pos + 1 << " ";
  }
  cout << '\n';

  return 0;
}
