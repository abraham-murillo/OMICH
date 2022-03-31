#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define fore(i, l, r) for (int i = l; i < r; i++)

const int N = 1e6 + 5;

int arbol[N];
int n;
long long m;

long long cortar(int sierra) {
  // la cantidad de madera que obtengo si pongo la sierra en
  // altura sierra

  long long sum = 0;
  fore (i, 0, n) {
    if (arbol[i] > sierra) {
      // sí voy a obtener madera
      sum += arbol[i] - sierra;
    } else {
      // no voy a obtenerla, es más peque el arbol
      break;
    }
  }

  // debug(sierra, sum);

  return sum >= m;
}

int bruta() {
  // Probar todos los posibles valores
  // f(i) < f(i+1), hay una condición de orden
  // corroborar que tu solución con la binaria sí esté bien
  for (int sierra = arbol[0]; sierra >= 0; sierra--) {
    if (cortar(sierra)) {
      return sierra;
    }
  }
  return -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> n >> m) {
    debug(m);
    fore (i, 0, n) {
      cin >> arbol[i];
    }

    // Ordenados de mayor a menor
    sort(arbol, arbol + n, [&](int x, int y) {
      return x > y;
    });

    // Binaria bien easy
    // La altura más grande
    int inicio = 0, fin = arbol[0] + 1;
    while (inicio + 1 < fin) {
      int mid = (inicio + fin) / 2;

      if (cortar(mid)) {
        // La sierra en altura mid ya me sirve, buscar una altura más grande
        inicio = mid;
      } else {
        // No me alcanza, necesito una sierra más peque
        fin = mid;
      }
    }

    debug(inicio, cortar(inicio));
    debug(fin, cortar(fin));

    cout << inicio << '\n';

    debug(bruta());
    debug("");
  }

  return 0;
}