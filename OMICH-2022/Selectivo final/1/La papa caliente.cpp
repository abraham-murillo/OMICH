#include <bits/stdc++.h>
//#include "debug.h"
#define fore(i, a, z) for (int i = a; i < z; i++)
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int a, b, c, time = 0;
  cin >> a >> b >> c;
  for (; time < 45;) {
    time += a;
    if (time < 45) {
      time += b;
      if (time < 45) {
        time += c;
        if (time >= 45) {
          cout << "Ramona ";
        }
      } else {
        cout << "Lorena ";
      }
    } else {
      cout << "Maeva ";
    }
  }
}