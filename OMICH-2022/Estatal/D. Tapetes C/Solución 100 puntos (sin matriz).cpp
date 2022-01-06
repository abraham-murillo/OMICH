#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n;
  cin >> n;

  int lim = 2 * n - 1;

  for (int i = 1; i <= lim; i++) {
    for (int j = 1; j <= lim; j++) {
      int paraArriba = i;
      int paraAbajo = lim - i + 1;
      int paraIzquierda = j;
      int paraDerecha = lim - j + 1;
      int mejorIzquierdaDerecha = min(paraIzquierda, paraDerecha);
      int mejorArribaAbajo = min(paraArriba, paraAbajo);
      int paredMasCercana = min(mejorIzquierdaDerecha, mejorArribaAbajo);
      cout << n - paredMasCercana + 1 << " ";
    }
    cout << '\n';
  }

  return 0;
}
