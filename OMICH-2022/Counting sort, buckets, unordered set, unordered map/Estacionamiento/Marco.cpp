#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fore(i, a, z) for (int i = a; i < z; i++)

int main() {
  vector<int> mapa(100 + 5, 0);
  int a, b, c, n = 3;
  cin >> a >> b >> c;
  while (n--) {
    pair<int, int> tim;
    cin >> tim.first >> tim.second;
    int time = tim.second - tim.first;

    for (int i = tim.first, j = 0; j < time; j++) {
      mapa[i]++;
      i++;
    }
  }
  int total = 0;
  for (auto i : mapa) {
    if (i == 1) {
      total += a;
    } else if (i == 2) {
      total += b * 2;
    } else if (i == 3) {
      total += c * 3;
    }
  }
  cout << total << endl;
}