#include <bits/stdc++.h>
using namespace std;

struct MaxStack {
  // Mantenemos la stack y una estructura que nos permita conocer el más grande rápido
  // Puede ser un multiset, map, priority_queue
  // Un set NO porque los elementos nos queddarían únicos
  stack<int> a;
  multiset<int> mx;

  void push(int x) {
    // Insertamos en x en la pila y en la estructura
    a.push(x);
    mx.insert(x);
  }

  int biggest() {
    // El máx grande es *mx.rbegin(), recuerden que rbegin() es el reverse begin(), el más pequeño sería begin()
    return *mx.rbegin();
  }

  void pop() {
    if (a.size()) {
      // Quitamos el tope de la stack de nuestra estructura, como es un multiset, se hace de esta forma
      mx.erase(mx.find(a.top()));
      // Quitamos el tope de la stack
      a.pop();
    }
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int op, x;
  MaxStack mx;
  while (n--) {
    cin >> op;

    if (op == 1) {
      cin >> x;
      mx.push(x);
    } else if (op == 2) {
      mx.pop();
    } else {
      cout << mx.biggest() << '\n';
    }
  }

  return 0;
}