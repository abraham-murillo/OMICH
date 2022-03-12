#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
int f[1000005];
int n;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  cin >> n;

  cin >> f[0] >> f[1] >> f[2];
  // Calculamos todos los f[i]
  for (int i = 3; i <= n; i++) {
    f[i] = ((f[i - 1] + f[i - 2]) % M + f[i - 3]) % M;
  }

  // Calculamos el prefix sum
  for (int i = 1; i <= n; i++) {
    (f[i] += f[i - 1]) %= M;
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    int ans = f[r];
    // Cuando se hace una resta bajo mod, se tiene que sumar mod para no tener un resultado negativo
    if (l != 0) {
      ans -= f[l - 1];
      ans += M;
      ans %= M;
    }

    cout << ans << '\n';
  }

  return 0;
}