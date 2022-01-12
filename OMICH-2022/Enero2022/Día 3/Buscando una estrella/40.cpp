#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  // Debería de dar TLE

  vector<long long> p;
  int n;

  cin >> n;

  char op;
  long long x;
  while (n--) {
    cin >> op;

    if (op == 'R') {
      cin >> x;
      p.push_back(x);
    } else if (op == 'S') {
      if (p.size() < 3) {
        cout << "NO HAY SUFICIENTES PUNTAJES\n";
        continue;
      }

      sort(p.begin(), p.end()); // Ordeno todo
      fore (i, 0, 3)
        cout << p[i] << " ";
      cout << '\n';
    } else {
      sort(p.begin(), p.end());
      if (!p.empty()) {
        // Muevo el más mini hasta el final
        swap(p[0], p.back());
        // Lo quito
        p.pop_back();
      }
    }
  }

  sort(p.begin(), p.end());

  if (p.empty()) {
    cout << "NO HUBO GANADOR\n";
  } else {
    cout << "EL PUNTAJE MAS ALTO FUE " << p.back() << '\n';
  }

  return 0;
}