#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fore(i, a, z) for (int i = a; i < z; i++)
int main() {
  int teo, teomax;
  cin >> teo >> teomax;
  int teoremas[teo];
  bool si[teo];
  fore (i, 0, teo) {
    cin >> teoremas[i];
  }
  fore (i, 0, teo) {
    cin >> si[i];
  }
  int total = 0;
  fore (i, 0, teo) {
    if (si[i]) {
      total += teoremas[i];
    }
  }
  int mx = teo;
  int suma = 0;
  for (int l = 1, r = 1; l < teo; l++) {
    while (r < teo - 1 && r - l < teomax) {
      suma += teoremas[r];
      if (si[r] && suma > 0) {
        suma -= teoremas[r];
      }
      r++;
    }

    mx = max(mx, suma);
    if (suma > 0 && !si[l]) {
      suma -= teoremas[l];
    }
  }
  cout << total + mx << endl;
}