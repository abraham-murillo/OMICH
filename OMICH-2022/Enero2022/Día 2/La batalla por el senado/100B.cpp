#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...)
#endif

bool cancelAndWin(string& s, deque<int>& a) {
  s[a.front()] = '.';
  a.pop_front();
  return a.size() <= 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  string s;
  while (cin >> s) {
    deque<int> jedi, sith;
    fore (i, 0, s.size())
      (s[i] == 'J' ? jedi : sith).push_back(i);
    debug(jedi, sith);

    char wins = '?';
    if (jedi.empty()) {
      wins = 'S';
    } else if (sith.empty()) {
      wins = 'J';
    } else {
      fore (i, 0, s.size()) {
        if (s[i] == '.')
          continue;

        if (cancelAndWin(s, s[i] == 'J' ? sith : jedi))
          wins = s[i];
        debug(s[i], jedi, sith);

        if (wins != '?')
          break;
      }
    }

    cout << (wins == 'J' ? "Perdiste Abraham" : "¡Yo soy el senado!") << '\n';
  }

  return 0;
}