#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int mat[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n;
  cin >> n;

  int izq = 1, der = 2 * n - 1;
  int arriba = 1, abajo = 2 * n - 1;

  int num = n;
  while (izq <= der) {
    for (int i = izq; i <= der; i++) {
      mat[arriba][i] = num;
      mat[abajo][i] = num;
    }

    for (int i = arriba; i <= abajo; i++) {
      mat[i][izq] = num;
      mat[i][der] = num;
    }

    izq++, der--;
    arriba++, abajo--;
    num--;
  }

  for (int i = 1; i <= 2 * n - 1; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      cout << mat[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}