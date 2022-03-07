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

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  fore (i, 0, n) {
    string paga;
    cin >> p[i].nombre >> paga >> p[i].experiencia;
    p[i].paga = stoll(paga.substr(1));
  }

  sort(p, p + n, [&](const Profe& a, const Profe& b) {
    if (a.experiencia != b.experiencia)
      return a.experiencia > b.experiencia;
    if (a.paga != b.paga)
      return a.paga < b.paga;
    return a.nombre < b.nombre;
  });

  fore (i, 0, n) {
    cout << p[i].nombre << " $" << p[i].paga << " " << p[i].experiencia << '\n';
  }

  return 0;
}