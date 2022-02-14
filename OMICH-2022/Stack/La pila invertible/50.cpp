#include <bits/stdc++.h>
using namespace std;

// Podemos simular literalmente lo que nos dicen y estar volteando nuestra pila
// Para voltear la pila podemos usar una pila auxiliar donde vamos a vacear todo nuestro contenido y podemos ver que es lo mismo que voltearla

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  string op;
  int x;
  stack<int> s;
  while (n--) {
    cin >> op;

    if (op == "AGREGA") {
      cin >> x;
      s.push(x);
    } else if (op == "QUITA") {
      cout << s.top() << '\n';
      s.pop();
    } else {
      stack<int> tmp;
      while (!s.empty()) {
        tmp.push(s.top());
        s.pop();
      }
      s = tmp;
    }
  }

  return 0;
}