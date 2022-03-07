#include <bits/stdc++.h>
#define fore(i, l, r) for (long i = (l); i < (r); i++)
using namespace std;
struct horas {
  int vh, d;
};
int main() {
  int n, k, aux = 0, t = 0, v = 0;
  cin >> n >> k;
  horas h[n];
  fore (i, 0, n) {
    cin >> h[i].vh;
  }
  fore (i, 0, n) {
    cin >> h[i].d;
    v += (h[i].vh * h[i].d);
  }
  // cout<<"      "<<v<<"       ";
  fore (i, 0, k - 1) {
    if (h[i].d == 0) {
      aux += h[i].vh;
    }
  }
  // cout<<"      "<<aux<<"       ";
  fore (i, k - 1, n) {
    if (h[i].d == 0) {
      aux += h[i].vh;
    }
    if (aux > t)
      t = aux;
    if (h[i - k + 1].d == 0)
      aux -= h[i - k + 1].vh;
  }
  cout << t + v;
}