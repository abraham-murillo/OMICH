#include <bits/stdc++.h>
using namespace std;

struct Persona {
  int edad, peso;

  friend istream& operator>>(istream& is, Persona& p) {
    is >> p.edad >> p.peso;
    return is;
  }

  friend ostream& operator<<(ostream& os, Persona& p) {
    os << p.edad << " " << p.peso;
    return os;
  }
};

int main() {
  Persona salones[4][1];

  for (int i = 0; i < 4; i++) { // iterar sobre filas
    for (int j = 0; j < 1; j++) { // iterar sobre columnas
      cin >> salones[i][j];
    }
  }

  for (int i = 0; i < 4; i++) { // iterar sobre filas
    for (int j = 0; j < 1; j++) { // iterar sobre columnas
      cout << salones[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}