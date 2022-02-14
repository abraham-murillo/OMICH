#include <bits/stdc++.h>
using namespace std;

struct MaxStack {
  // Mantenemos 2 stacks, una para el valor y otra para el máximo
  stack<int> a, mx;

  void push(int x) {
    // En la stack a, sólo agregamos el valor
    a.push(x);
    // En la stack mx, agregamos el máximo global, que es el máximo de nuestra stack y x (el nuevo valor)
    mx.push(mx.empty() ? x : max(mx.top(), x));
  }

  void pop() {
    // Si a tiene tamaño podemos hacer pop
    if (a.size()) {
      a.pop();
      mx.pop();
    }
  }

  int top() {
    // Nos interesa el más grande, así que regresamos el top de la stack mx
    return mx.top();
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
      cout << mx.top() << '\n';
    }
  }

  return 0;
}