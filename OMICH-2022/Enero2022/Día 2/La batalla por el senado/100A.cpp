#include <bits/stdc++.h>
using namespace std;

int main() {
  string senate;
  while (cin >> senate) {

    queue<int> jedi;
    queue<int> sith;
    for (int i = 0; i < senate.size(); i++) {
      if (senate[i] == 'J')
        jedi.push(i);
      else
        sith.push(i);
    }

    while (!jedi.empty() && !sith.empty()) {
      int j = jedi.front();
      jedi.pop();
      int s = sith.front();
      sith.pop();
      if (j < s)
        jedi.push(j + senate.size());
      else
        sith.push(s + senate.size());
    }

    if (jedi.empty())
      cout << "¡Yo soy el senado!" << '\n';
    else
      cout << "Perdiste Abraham" << '\n';
  }
  return 0;
}