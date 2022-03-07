#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, z) for (int i = a; i < z; i++)

int main() {
  unordered_map<int, int> dif;
  int per, equipo, cont = 0;
  cin >> per >> equipo;
  int arr[per];
  fore (i, 0, per) {
    cin >> arr[i];
  }
  for (int l = 0, r = 0; l <= per; l++) {

    while (r - l < equipo && r < per) {
      dif[arr[r]]++;
      r++;
    }
    if (dif.size() == equipo) {
      cont++;
    }
    if (dif[arr[l]] > 1) {
      dif[arr[l]]--;
    } else {
      dif.erase(arr[l]);
    }
  }
  cout << cont << endl;
}