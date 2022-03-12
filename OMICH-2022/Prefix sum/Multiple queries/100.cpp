#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define fore(i, l, r) for (int i = l; i < r; i++)

const int N = 1e5 + 5;

using lli = long long;

struct Range {
  int l, r;

  bool inRange(int x) {
    // Para que un punto esté en el rango debe de estar entre l y r
    return l <= x && x <= r;
  }

  bool canMerge(Range range) {
    // Dos rangos se pueden juntar si la izquierda o derecha está entre los límites del otro
    return inRange(range.l) || inRange(range.r);
  }

  void merge(Range range) {
    // Para mezclar 2 rangos, la izquierda es el mínimo de los dos y la derecha el máximo
    l = min(l, range.l);
    r = max(r, range.r);
  }
};

lli sum[N];
int a[N];
int n, q;

lli query(int l, int r) {
  return sum[r] - sum[l - 1];
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;

  // Hacemos el prefix sum
  fore (i, 1, n + 1) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  cin >> q;
  while (q--) {
    int k;
    cin >> k;

    vector<Range> ranges;
    fore (i, 0, k) {
      int l, r;
      cin >> l >> r;
      ranges.push_back({l, r});
    }

    // Ordenamos todos los rangos por el que empiece primero (la izquierda más pequeña)
    sort(ranges.begin(), ranges.end(), [&](Range a, Range b) {
      return a.l < b.l;
    });

    /*
    Vamos a ir juntado rangos y haciendo preguntas al prefix sum
    Para hacer esto (juntar rangos) tomamos el rango más a la izquieda e intentamos agregar uno a su derecha siempre y tengan algún punto en común con
    el anterior, de ser así los juntamos ambos rangos ("extendemos los límites") hacemos esto hasta que ya no se pueda, usamos two-pointers para
    seguir probando rangos a la derecha, cuando ya no se puede agregamos la suma y volvemos a repetir lo anterior.
    */
    int i = 0;
    lli ans = 0;
    while (i < k) {
      Range cur = ranges[i];
      // Two pointers intentando juntar rangos
      int j = i + 1;
      while (j < k && cur.canMerge(ranges[j])) {
        cur.merge(ranges[j]);
        j++;
      }

      // Ya no se pueden juntar, hacemos la query y empezamos con un nuevo rango
      ans += query(cur.l, cur.r);
      i = j;
    }

    cout << ans << '\n';
  }

  return 0;
}