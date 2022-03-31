#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define fore(i, l, r) for (int i = l; i < r; i++)

int pos[N];
int n, p;

bool can(int dist) {
  // Para acomodarlos, nos conviene asignar al primer programador en la primera posición y seguir acomodando el que sigue en cuanto se pueda, es
  // decir, cuando esté a una distancia mayor o igual que "dist"
  int last = pos[0];
  int cnt = 1;

  fore (i, 0, n) {
    if (pos[i] - last >= dist) {
      last = pos[i];
      cnt++;
    }
    if (cnt >= p)
      break;
  }

  // Si hay más de p lugares, esta distancia se puede :D
  return cnt >= p;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> n >> p;
  fore (i, 0, n) {
    cin >> pos[i];
  }

  // Primero tenemos que ordenar todas las posiciones donde pueden estar los programadores
  sort(pos, pos + n);

  // La idea es asignar una "distancia" mínima y ver si es posible acomodarlos
  int lo = 0, hi = pos[n - 1] + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (can(mid))
      lo = mid;
    else
      hi = mid;
  }

  cout << lo << '\n';

  return 0;
}