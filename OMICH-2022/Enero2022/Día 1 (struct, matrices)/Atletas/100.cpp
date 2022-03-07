#include <bits/stdc++.h>
using namespace std;

struct Atleta {
  string nombre;
  int hab, exp;

  bool operator < (const Atleta& at) {
    if (at.hab == hab) {
      return exp < at.exp;
    }
    return hab < at.hab;
  }

  friend istream &operator >> (istream& is, Atleta& at) {
    return is >> at.nombre >> at.hab >> at.exp;
  }

  friend ostream &operator << (ostream& os, const Atleta& at) {
    return os << at.nombre << " " << at.hab << " " << at.exp;
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int n; cin >> n;

  Atleta a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if (a[l] < a[r]) {
      swap(a[l], a[r]);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << '\n';
  }

  return 0;
}