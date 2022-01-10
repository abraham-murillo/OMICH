#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = (l); i < (r); i++)
#define debug(x) cout << #x << ": " << (x) << endl;

using lli = long long;

// int = entero, valor Entero
// double, numero con decimales

// dos campos
using Frac2 = pair<pair<int, int>, lli>;
// first {first, second}, second

struct Frac {
  lli num, den;

  // Frac() {}

  Frac(lli a = 0, lli b = 1) {
    num = a;
    den = b;
  }

  // +*-/ >> << () []

  // actual + f

  Frac operator+(Frac f) {
    Frac tmp;
    tmp.num = num + f.num;
    tmp.den = den;
    return tmp;
  }

  friend ostream& operator<<(ostream& os, Frac f) {
    // Imprimir una struct
    // os = cout
    // 3/5
    os << f.num << "/" << f.den;
    return os;
  }

  friend istream& operator>>(istream& is, Frac& f) {
    // Leer una struct
    // is = cin
    is >> f.num >> f.den;
    return is;
  }

  bool operator==(Frac f) {
    return num == f.num && den == f.den;
  }

  bool operator<(Frac f) {
    return double(num) / double(den) < double(f.num) / double(f.den);
  }
};

// Frac = 1/6 + 1/8
// Frac a = 1/6
// Frac b = 1/8
// Frac c = a + b

struct Fecha {
  int dia;
  int mes;
  int anyo;
};

struct Persona {
  string nombre;
  string apellido;
  int edad;
  Fecha nac;

  string nombreCompleto() {
    return nombre + " " + apellido;
  }

  void imprimir() {
    cout << "nombre: " << nombre << " " << apellido << '\n';
    cout << "edad: " << edad << '\n';
  }

  string nacimientoToString() {
    return to_string(nac.dia) + "/" + to_string(nac.mes) + "/" + to_string(nac.anyo);
  }
};

int main() {

  Persona p1, p2;

  cin >> p1.nombre >> p1.apellido >> p1.edad;

  // cin >> p1.nacimiento.dia >> p1.nacimiento.mes >> p1.nacimiento.anyo;

#define n nac
  p1.n.dia = 14;
  p1.n.mes = 6;
  p1.n.anyo = 2000;

  p1.imprimir();

  debug(p1.nombre);
  debug(p1.apellido);
  debug(p1.edad);
  debug(p1.nombreCompleto());
  debug(p1.nacimientoToString());

  /*
  debug(p1.n.dia);
  debug(p1.n.mes);
  debug(p1.n.anyo);

  p2.nombre = "Roberto";
  p2.apellido = "Pino";
  p2.edad = 20;

  debug(p2.nombre);
  debug(p2.apellido);
  debug(p2.edad);
  debug(p2.nombreCompleto());
  */

  Frac vacia;
  debug(vacia);

  Frac f(5);
  debug(f);

  Frac tmp(4, 5);
  debug(tmp);

  Frac a;
  a.num = 1;
  a.den = 6;

  Frac b;
  b.num = 2;
  b.den = 6;

  Frac c = a + b;

  debug(c.num);
  debug(c.den);

  debug(c);

  // cin >> c;
  // debug(c);
  // cout << c << '\n';

  debug(a);
  debug(a == c);
  debug(a == a);

  debug(a < c);
  debug(a < a);

  // 1/8 > 1/9
  // 1/8 == 1/8
  // 1/8 != 1/7

  return 0;
}