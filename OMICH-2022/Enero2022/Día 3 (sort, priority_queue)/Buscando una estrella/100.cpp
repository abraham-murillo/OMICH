#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  priority_queue<long long> pq;
  int n;

  cin >> n;

  char op;
  long long x;
  while (n--) {
    cin >> op;

    if (op == 'R') {
      cin >> x;
      pq.push(-x);
    } else if (op == 'S') {
      if (pq.size() < 3) {
        cout << "NO HAY SUFICIENTES PUNTAJES\n";
        continue;
      }

      vector<long long> tmp;
      fore (it, 0, 3) {
        tmp.push_back(pq.top());
        pq.pop();
      }

      fore (i, 0, 3) {
        if (i > 0)
          cout << " ";
        cout << -tmp[i];
        pq.push(tmp[i]);
      }
      cout << '\n';
    } else {
      if (!pq.empty())
        pq.pop();
    }
  }

  if (pq.empty()) {
    cout << "NO HUBO GANADOR\n";
  } else {
    while (pq.size() > 1)
      pq.pop();

    cout << "EL PUNTAJE MAS ALTO FUE " << -pq.top() << '\n';
  }

  return 0;
}