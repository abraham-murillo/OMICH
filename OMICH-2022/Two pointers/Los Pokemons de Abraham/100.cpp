#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

const int N = 1e5 + 5;
const int K = 255;

struct Pokemon {
  // Estructura que mantiene los caracteres diferentes
  int cnt[K];
  int diferentes = 0;

  Pokemon() {
    fore (i, 0, K)
      cnt[i] = 0;
  }

  void agregar(char c) {
    cnt[c]++;
    if (cnt[c] == 1) {
      diferentes++;
    }
  }

  void quitar(char c) {
    cnt[c]--;
    if (cnt[c] == 0) {
      diferentes--;
    }
  }
};

string p;
int n;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> n >> p) {
    Pokemon todos;
    for (char c : p)
      todos.agregar(c);

    debug(p);
    debug(todos.diferentes);

    // La menor cantidad de bitcoins posibles que Abraham debe de gastar para poder convivir con todos los tipos de Pokémon existentes en el refugio.

    // Rango más chiquito es la respuesta
    int mn = n;
    Pokemon convivir;
    for (int l = 0, r = 0; l < n; l++) {
      while (r < n && convivir.diferentes < todos.diferentes) {
        // Todavía me falta más pokemones
        convivir.agregar(p[r]);
        r++;
      }

      debug("Rango", l, r - 1, convivir.diferentes, "tomando", r - l);

      if (convivir.diferentes == todos.diferentes) {
        // Necesito tener todos los pokemones diferentes para considerar el rango como respuesta
        mn = min(mn, r - l);
      }

      // Ignoren esto xd
      convivir.quitar(p[l]);
    }

    cout << mn << '\n';
  }

  return 0;
}
