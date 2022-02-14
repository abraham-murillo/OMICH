#include <bits/stdc++.h>
using namespace std;

// Lo importante en este problema es ver que o agregamos del lado izquierdo o del lado derecho,
// Si agregamos del lado izquiedo, sacamos del derecho y viceversa
// Una estructura que hace eso es una deque, sólo hay que recordar de qué lado estamos agregando

struct Stack {
  deque<int> a;
  bool inv = 0;

  void push(int x) {
    inv ? a.push_front(x) : a.push_back(x);
  }

  int top() {
    return inv ? a.front() : a.back();
  }

  void pop() {
    inv ? a.pop_front() : a.pop_back();
  }

  void inverse() {
    inv ^= 1;
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  string op;
  int x;
  Stack s;
  while (n--) {
    cin >> op;

    if (op == "AGREGA") {
      cin >> x;
      s.push(x);
    } else if (op == "QUITA") {
      cout << s.top() << '\n';
      s.pop();
    } else {
      s.inverse();
    }
  }

  return 0;
}