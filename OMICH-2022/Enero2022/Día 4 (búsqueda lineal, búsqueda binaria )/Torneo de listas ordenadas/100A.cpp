#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int l, n, k;
  while (cin >> l >> n >> k) {
    vector<queue<int>> a(l);
    fore (i, 0, l) {
      fore (j, 0, n) {
        int x;
        cin >> x;
        a[i].push(x);
      }
    }

    while (--k) {
      // Obtenemos el valor más peque
      int peque = -1;
      fore (i, 0, l) {
        if (a[i].empty()) {
          continue;
        }
        if (peque == -1 || a[i].front() < a[peque].front()) {
          peque = i;
        }
      }

      // Quitamos al más peque de su lista
      a[peque].pop();
    }

    vector<int> start;
    fore (i, 0, l) {
      start.push_back(a[i].empty() ? 1e9 : a[i].front());
    }

    while (l >= 1) {
      // Imprimimos la respuesta
      for (auto& x : start)
        cout << (x < 1e9 ? x : -1) << " ";
      cout << '\n';

      vector<int> nxt;
      for (int i = 0; i < start.size(); i += 2)
        nxt.push_back(min(start[i], start[i + 1]));

      swap(start, nxt);
      l /= 2;
    }
  }

  return 0;
}
