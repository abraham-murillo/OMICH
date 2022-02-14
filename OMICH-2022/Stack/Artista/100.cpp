#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (auto i = (l); i < (r); i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

struct Papel {
  stack<int> pila;

  int color() {
    // Cual es el color que se ve desde arriba
    return pila.size() ? pila.top() : -1;
  }

  void agregar(int c) {
    // Dependiendo de c agregamos/quitamos, revisando que sí se pueda
    if (c == -1) {
      if (pila.size())
        pila.pop();
    } else {
      pila.push(c);
    }
  }

  void clear() {
    while (!pila.empty())
      pila.pop();
  }
};

struct Rectangulo {
  int c, m, n, i, j;
};

const int N = 205;

// Una matriz de papel, cada papel se encarga de agregar/quitar colores
Papel cartulina[N][N];
int n, m, g, c, k;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> m >> n >> g >> c) {
    fore (i, 1, n + 1)
      fore (j, 1, m + 1) {
        cartulina[i][j].clear();
        fore (it, 0, g)
          cartulina[i][j].agregar(c);
      }

    cin >> k;
    while (k--) {
      Rectangulo adhesivo;
      cin >> adhesivo.c >> adhesivo.m >> adhesivo.n >> adhesivo.j >> adhesivo.i;

      // Agregamos en la submatriz el último color del papel
      fore (i, 0, adhesivo.n)
        fore (j, 0, adhesivo.m)
          cartulina[adhesivo.i + i][adhesivo.j + j].agregar(adhesivo.c);
    }

    // Imprimimos
    fore (i, 1, n + 1) {
      fore (j, 1, m + 1)
        cout << cartulina[i][j].color() << " ";
      cout << '\n';
    }

    debug("");
  }

  return 0;
}
