#include <bits/stdc++.h>
using namespace std;

int main() {
  string cad;
  cin >> cad;

  int x = 0, y = 0;
  for (int i = 0; i < cad.size() / 2; i++) {
    if (cad[i] >= 'a' && cad[i] <= 'z')
      x += cad[i] - 'a';
    else if (cad[i] >= 'A' && cad[i] <= 'Z')
      x += cad[i] - 'A';
    else
      x += cad[i] - '0';
  }

  for (int i = cad.size() / 2; i < cad.size(); i++) {
    if (cad[i] >= 'a' && cad[i] <= 'z')
      y += cad[i] - 'a';
    else if (cad[i] >= 'A' && cad[i] <= 'Z')
      y += cad[i] - 'A';
    else
      y += cad[i] - '0';
  }

  cout << x << "," << y << '\n';

  return 0;
}