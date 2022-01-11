#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = (l); i < (r); i++)

int main() {
  string s;
  cin >> s;

  int jedi = 0, sith = 0;
  fore (i, 0, s.size()) {
    if (votos[i] == 'S')
      sith++;
    else if (votos[i] == 'J')
      jedi++;
  }

  if (sith > jedi)
    cout << "¡Yo soy el senado!";
  else
    cout << "Perdiste Abraham";

  return 0;
}