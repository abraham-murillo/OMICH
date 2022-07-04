#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define fore(i, a, z) for (int i = a; i < z; i++)
#define endl '\n'

using namespace std;

int main() {
  char opc;
  int alimento = 0;
  deque<string> animals;
  while (cin >> opc) {
    if (opc == 'N') {
      string animal;
      cin >> animal;
      animals.push_back(animal);
    } else if (opc == 'S') {
      if (!animals.empty()) {
        cout << animals.front() << endl;
        animals.pop_front();
      }
    } else if (opc == 'C') {
      int x;
      cin >> x;
      alimento += x;
    } else if (opc == 'A') {
      if (alimento <= 0) {
        while (!animals.empty()) {
          cout << animals.back() << endl;
          animals.pop_back();
        }
        return 0;
      } else {
        int porcion = alimento / animals.size();
        cout << porcion << endl;
        alimento -= porcion * animals.size();
      }
    } else if (opc == 'F') {
      cout << animals.size() << endl;
    }
  }
}