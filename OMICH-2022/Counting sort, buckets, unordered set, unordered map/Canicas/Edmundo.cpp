#include <bits/stdc++.h>
using namespace std;
#define fore(i, l, r) for (int i = (l); i < (r); i++)

int main() {
  int v, c, aux;
  cin >> v >> c;

  map<int, int> vc;
  fore (i, 0, c) {
    cin >> aux;
    vc[aux - 1]++;
  }

  fore (i, 0, v) {
    cout << vc[i] << "\n";
  }
}