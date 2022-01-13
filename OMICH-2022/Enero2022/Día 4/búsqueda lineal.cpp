#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...)
#endif

vector<int> a = {0, 1, 7, 5, 3, 4, 5, 6, 7, 5, 5, 10};

bool existe(int x) {
  // O(a.size())
  fore (i, 0, a.size()) {
    if (a[i] == x)
      return true;
  }
  return false;
}

int primeraPosicion(int x) {
  fore (i, 0, a.size()) {
    if (a[i] == x)
      return i;
  }
  return -1;
}

vector<int> todasLasPosiciones(int x) {
  vector<int> pos;
  fore (i, 0, a.size()) {
    if (a[i] == x)
      pos.push_back(i);
  }
  return pos;
}

struct Rango {
  int primero;
  int ultimo;

  friend ostream& operator<<(ostream& salida, const Rango& r) {
    return salida << "primero: " << r.primero << ", ultimo: " << r.ultimo;
  }
};

Rango primeroUltimo(int x) {
  Rango rango = {int(1e9), int(-1e9)};
  fore (i, 0, a.size()) {
    if (a[i] == x) {
      rango.primero = min(rango.primero, i);
      rango.ultimo = max(rango.ultimo, i);
    }
  }
  return rango;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  // Búsqueda lineal
  debug(a);
  debug(existe(5));
  debug(existe(12));

  debug(primeraPosicion(5));
  debug(primeraPosicion(12));

  debug(todasLasPosiciones(5));
  debug(todasLasPosiciones(7));
  debug(todasLasPosiciones(12));

  debug(primeroUltimo(5));
  debug(primeroUltimo(7));
  debug(primeroUltimo(12));

  // Búsqueda binaria

  return 0;
}