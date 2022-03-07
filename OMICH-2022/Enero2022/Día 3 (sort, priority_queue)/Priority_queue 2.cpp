#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 
#endif


struct Persona {
  string nombre;
  int edad;

  bool operator < (const Persona &p) const {
    if (edad != p.edad) {
      return !(edad < p.edad);
    }
    return !(nombre < p.nombre);
  }

  friend ostream &operator << (ostream &os, Persona p) {
      os << p.nombre << " " << p.edad;
      return os;
  }
};

priority_queue<Persona> pq;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
//   Persona p1 = {"Pino", 20};
    // pq.push(p1);
    pq.push({"Pino", 20});
    debug(pq.top()); // {"Pino", 20}

    pq.push({"Abraham", 21});
    debug(pq.top()); // {"Pino", 20}

    pq.push({"Jessica", 16});
    debug(pq.top()); // {"Jessica", 16}

    pq.push({"Edmundo", 16});
    debug(pq.top()); // {Edmundo, 16}

    pq.push({"Isauro", 16});
    debug(pq.top()); // {"Edmundo", 16}

  return 0;
}