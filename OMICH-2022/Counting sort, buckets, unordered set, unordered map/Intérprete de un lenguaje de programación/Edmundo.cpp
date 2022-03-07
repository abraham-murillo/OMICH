#include <bits/stdc++.h>
//#include "debug.h"
#define fore(i, l, r) for (long long i = (l); i < (r); i++)
#define ll long long
using namespace std;
int main() {
  string s = "", er = "ERROR L";
  string ci = "", aux = "";
  ll in = 0;
  map<string, ll> m;
  map<ll, ll> vals;
  while (cin >> s) {
    cin >> ci;
    in += 1;

    if (s[0] == 'V') {
      if (m[ci] == 0) {
        m[ci] = in;
        vals[m[ci]] = 1;
      } else
        cout << er << in << "\n";
    } else if (s[0] == 'R') {
      cin >> aux;
      if (m[aux] != 0 && m[ci] == 0) {
        m[ci] = m[aux];
      } else
        cout << er << in << "\n";
    } else if (s[0] == 'I') {
      if (m[ci] != 0) {
        vals[m[ci]]++;
      } else
        cout << er << in << "\n";
    } else if (s[0] == 'P') {
      if (m[ci] != 0) {
        cout << vals[m[ci]] - 1 << "\n";
      } else
        cout << er << in << "\n";
    }
  }
}