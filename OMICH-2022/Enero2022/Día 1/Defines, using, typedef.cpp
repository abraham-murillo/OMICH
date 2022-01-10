#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = (l); i < (r); i++)
#define lli long long
#define PI 3.1416

#define debug(x) cout << #x << ": " << (x) << endl;

long long a;
lli b;

enum { LEER = 1, ESCRIBIR = 10, SALIR = 3 };
enum { Leer = 1, Escribir, Salir, Jessica = 10, Edmundo, Roberto };

using Entero = int;
// using ll = long long; // > C++14
typedef long long ll; // <= C++11

using vi = vector<int>;
using arr = array<int, 10>;

int main() {

  ll c, d;
  cin >> c >> d;
  debug(c);
  debug(d);

  cin >> a >> b;
  cout << a << " " << b << '\n';
  debug(a);
  debug(b);
  
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < a; j++) {
      cout << i << '\n';
    }
  }

  fore (i, 0, b) {
    fore (j, 0, a) {
      // cout << i << " " << j << '\n';
      debug(i);
      debug(j);
    }
  }

  cout << PI << '\n';
  debug(PI);

  /*
  if (op == LEER) {

   } else if (op == ESCRIBIR {

   } else if (op == SALIR) {

   }
   */

  debug(Leer);
  debug(Escribir);
  debug(Salir);
  debug(Jessica);
  debug(Edmundo);
  debug(Roberto);

  return 0;
}