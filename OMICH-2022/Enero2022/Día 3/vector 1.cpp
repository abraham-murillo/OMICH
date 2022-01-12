#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...)
#endif

#define fore(i, l, r) for (int i = l; i < r; i++)

// sort -> ordenar

const int N = 10;
int a[N] = {0, 5, 6, 7, 8, 1, 2, 4, 3, 9};
vector<int> b = {0, 5, 6, 7, 8, 1, 2, 4, 3, 9};

bool orden1(int x, int y) {
  // x debería de ir a la izquiera
  // y debería de ir a la derecha
  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9  a[i] < a[i + 1]
  return x < y;
}

bool orden2(int x, int y) {
  // 9, 8, 7, 6, 5, 4, 3, 2, 1, 0  a[i] > a[i + 1]
  return x > y;
}

bool orden3(int x, int y) {
  // 0, 2, 4, 6, 8, 1, 3, 5, 7, 9
  if (x % 2 != y % 2) {
    return x % 2 < y % 2;
  }
  return x < y;
}

bool orden4(int x, int y) {
  // 1, 3, 5, 7, 9      0, 2, 4, 6, 8,
  if (x % 2 != y % 2) {
    return x % 2 > y % 2;
  }
  return x < y;
}

void bubbleSort() {
  // Bubble sort
  {
    int n = N;
    // a[i] <= a[i + 1]
    debug("Antes", a);
    int operaciones = 0;
    fore (correctosDerecha, 0, n) {
      for (int pos = 0; pos + 1 < n - correctosDerecha; pos++) {
        operaciones++;
        if (!orden3(a[pos], a[pos + 1])) {
          swap(a[pos], a[pos + 1]); // Intercambia a[pos] con a[pos+1]
        }
      }
    }
    debug("Después", a);
    debug(n, operaciones);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  // bubbleSort();
  // O(n * (n - 1) / 2) = O((n^2 - n) / 2) = O(n^2)
  // insertionSort, selectionSort, ...
  // mergeSort, quickSort (sí se usan)

  // O(n log n)
  // a+5 = a[5]

  debug("Antes", a);
  sort(a, a + N, orden3); // a[i] < a[i+1]
  debug("Después", a);

  debug(b);
  sort(b.begin(), b.end(), orden4);
  debug(b);

  return 0;
}
