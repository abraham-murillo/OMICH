#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...)
#endif

#define fore(i, l, r) for (int i = l; i < r; i++)

struct Persona {
  string nombre;
  int edad;
  int pos;

  friend ostream& operator<<(ostream& os, const Persona& p) {
    return os << p.nombre << " " << p.edad;
  }

  bool operator<(Persona p) {
    return edad < p.edad;
  }
};

const int N = 100;

Persona p[N] = {{"Pino", 20},     {"Jessica1", 16}, {"Isauro1", 16},  {"Edmundo1", 16}, {"Jessica2", 16}, {"Isauro2", 16},  {"Edmundo2", 16},
                {"Jessica3", 16}, {"Isauro3", 16},  {"Edmundo3", 16}, {"Jessica4", 16}, {"Isauro4", 16},  {"Edmundo4", 16}, {"Jessica4", 16},
                {"Isauro5", 16},  {"Edmundo5", 16}, {"Jessica5", 16}, {"Isauro6", 16},  {"Edmundo6", 16}, {"Jessica6", 16}, {"Isauro7", 16},
                {"Edmundo7", 16}, {"Jessica7", 16}, {"Isauro8", 16},  {"Edmundo8", 16}, {"Jessica8", 16}, {"Isauro9", 16},  {"Edmundo9", 16},
                {"Jessica9", 16}, {"Isauro10", 16}, {"Edmundo10", 16}};

bool orden(Persona p1, Persona p2) {
  if (p1.edad != p2.edad)
    return p1.edad < p2.edad;
  return p1.nombre < p2.nombre;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  debug(p);

  // Usando una función
  // sort(p + 2, p + 5, orden);

  // Usando el operador en la struct
  // sort(p, p + N);

  // Funciones lambda
  // sort(p, p + n, [&](Persona p1, Persona p2) {
  //   if (p1.edad != p2.edad)
  //     return p1.edad < p2.edad;
  //   return p1.nombre < p2.nombre;
  // });

  // auto ordenLambda = [&](Persona p1, Persona p2) {
  //   if (p1.edad != p2.edad)
  //     return p1.edad < p2.edad;
  //   return p1.nombre < p2.nombre;
  // };
  // sort(p, p + n, ordenLambda);

  // Como conservar el orden al ordenar

  // fore (i, 0, N)
  //   p[i].pos = i;

  // sort(p, p + N, [&](Persona a, Persona b) {
  //   if (a.edad != b.edad)
  //     return a.edad < b.edad;
  //   return a.pos < b.pos;
  // });

  stable_sort(p, p + N);

  debug(p);

  return 0;
}
