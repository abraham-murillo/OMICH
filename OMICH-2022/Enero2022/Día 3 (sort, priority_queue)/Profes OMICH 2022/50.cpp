#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using lli = long long;

struct Profe {
  string nombre;
  lli paga;
  int experiencia;
};

const int N = 1e5 + 5;
Profe p[N];
int n;

bool orden(const Profe& a, const Profe& b) {
  if (a.experiencia != b.experiencia)
    return a.experiencia > b.experiencia;
  if (a.paga != b.paga)
    return a.paga < b.paga;
  return a.nombre < b.nombre;
}

void bubbleSort() {
  fore (correctosDerecha, 0, n) {
    for (int pos = 0; pos + 1 < n - correctosDerecha; pos++) {
      if (!orden(p[pos], p[pos + 1])) {
        swap(p[pos], p[pos + 1]); // Intercambia
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  char trash;
  fore (i, 0, n) {
    cin >> p[i].nombre >> trash >> p[i].paga >> p[i].experiencia;
  }

  bubbleSort();

  fore (i, 0, n) {
    cout << p[i].nombre << " $" << p[i].paga << " " << p[i].experiencia << '\n';
  }

  return 0;
}