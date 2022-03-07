#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, z) for (int i = a; i <= z; i++)
int N = 1000000 + 5;

int main() {
  vector<int> cubeta(N, 0);
  int n, can, cont;
  cin >> n >> can;
  for (int i = 1; i <= can; i++) {
    cin >> cont;
    cubeta[cont]++;
  }
  fore (i, 1, n) {
    cout << cubeta[i] << endl;
  }
}