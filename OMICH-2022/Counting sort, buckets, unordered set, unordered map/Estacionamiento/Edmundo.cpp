#include <bits/stdc++.h>
using namespace std;
#define fore(i, l, r) for (int i = (l); i < (r); i++)

int main() {
  int a, b, c, aux = 0, p = 0;
  cin >> a >> b >> c;
  int tiempos[6];
  fore (i, 0, 6) {
    cin >> tiempos[i];
    if (tiempos[i] > aux)
      aux = tiempos[i];
  }
  vector<int> h(101, 0);
  fore (i, tiempos[0], tiempos[1]) {
    h[i]++;
  }
  fore (i, tiempos[2], tiempos[3]) {
    h[i]++;
  }
  fore (i, tiempos[4], tiempos[5]) {
    h[i]++;
  }
  fore (i, 0, aux + 1) {
    if (h[i] == 1)
      p += a;
    else if (h[i] == 2)
      p += b * 2;
    else if (h[i] == 3)
      p += c * 3;
  }
  cout << p;
}
