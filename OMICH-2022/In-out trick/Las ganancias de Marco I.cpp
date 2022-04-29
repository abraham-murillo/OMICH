#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ld = long double;
using lli = long long;
using ii = pair<int, int>;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

const int N = 1e5 + 5;

vector<int> in[N], out[N];
lli ans[N];
int a[N];
int n, q;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  fore (i, 1, n + 1)
    cin >> a[i];

  cin >> q;
  fore (i, 1, q + 1) {
    int a, b;
    cin >> a >> b;
    // Para la i-ésima pregunta entra en 'a'
    in[a].push_back(i);
    // Para la i-ésima pregunta sale en 'b'
    out[b].push_back(i);
  }

  lli sum = 0;
  fore (pos, 0, n + 1) {
    // Separar la query en:
    //  sum(a, b) = sum(b) - sum(a - 1)
    debug(pos);

    // in -> -sum
    // Para todas las queries que entran yo le quito sum
    debug(in[pos], sum);
    for (int queryId : in[pos])
      ans[queryId] -= sum;

    // Agregar el valor a mi estado
    debug(sum, "agregar", a[pos]);
    sum += a[pos];

    // out -> +sum
    // Para todas las queries que salen yo le agrego sum
    debug(out[pos], sum);
    for (int queryId : out[pos])
      ans[queryId] += sum;

    debug("");
  }

  fore (queryId, 1, q + 1) {
    debug(queryId);
    cout << ans[queryId] << '\n';
  }

  return 0;
}