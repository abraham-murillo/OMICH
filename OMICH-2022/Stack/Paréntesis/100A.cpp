#include <bits/stdc++.h>
using namespace std;

// Como se explicó en clase, si es un ( agregamos a la stack, si es ) intentamos ver si hay uno en la stack para emparejarse, si lo hay quitamos uno
// de la stack, sino es una solución incorrecta La string está balanceada si al final no hay ningún caracter en la stack

string s;

bool isGood() {
  stack<char> balance;
  for (char c : s) {
    if (c == '(') {
      balance.push(c);
    } else {
      if (balance.empty())
        return false;
      balance.pop();
    }
  }
  return balance.empty();
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> s) {
    cout << (isGood() ? "SI" : "NO") << '\n';
  }

  return 0;
}