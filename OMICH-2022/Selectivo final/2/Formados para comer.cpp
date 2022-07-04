#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define fore(i, a, z) for (int i = a; i < z; i++)
#define endl '\n'

using namespace std;

queue<string> tacos;
queue<string> refr;

int main() {
  int n;
  cin >> n;
  while (n--) {
    string opc, que;
    cin >> opc >> que;
    debug(opc, que);
    if (opc == "LLEGA") {
      tacos.push(que);
    } else if (que == "TACO") {
      if (!tacos.empty()) {
        refr.push(tacos.front());
        tacos.pop();
      }
    } else {
      if (!refr.empty()) {
        refr.pop();
      }
    }
  }
  while (!tacos.empty()) {
    cout << tacos.front() << " ";
    tacos.pop();
  }
  cout << endl;
  while (!refr.empty()) {
    cout << refr.front() << " ";
    refr.pop();
  }
}