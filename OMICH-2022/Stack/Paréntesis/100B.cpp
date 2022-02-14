#include <bits/stdc++.h>
using namespace std;

// Como se explicó en clase, si es un ( agregamos a la stack, si es ) intentamos ver si hay uno en la stack para emparejarse, si lo hay quitamos uno
// de la stack, sino es una solución incorrecta La string está balanceada si al final no hay ningún caracter en la stack

// Podemos simular lo anterior pero con sumas, si es un ( sumamos 1, si es ) sumamos -1, la suma siempre tiene que ser >= 0 para poder restar y al
// final debe de ser exactamente 0

string s;

bool isGood() {
  int balance = 0;
  for (char c : s) {
    if (c == '(') {
      balance++;
    } else {
      if (balance == 0)
        return false;
      balance--;
    }
  }
  return balance == 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  while (cin >> s) {
    cout << (isGood() ? "SI" : "NO") << '\n';
  }

  return 0;
}