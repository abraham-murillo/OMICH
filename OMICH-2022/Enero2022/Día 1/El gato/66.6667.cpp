#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

const int N = 50;
char mat[N][N];
int cntRow[N][256], cntCol[N][256];
int n, m;

bool win(char who) {
  // horizontal, vertical
  fore (i, 0, n) {
    if (cntRow[i][who] >= 3)
      return 1;
    if (cntCol[i][who] >= 3)
      return 1;
  }

  // diagonal
  if (mat[0][0] == who && mat[1][1] == who && mat[2][2] == who)
    return 1;
  if (mat[2][0] == who && mat[1][1] == who && mat[0][2] == who)
    return 1;

  return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  fore (i, 0, n)
    fore (j, 0, n) {
      mat[i][j] = '.';
    }

  cin >> m;

  bool done = 0;
  fore (i, 1, m + 1) {
    int r, c;
    char who;
    cin >> r >> c >> who;
    --r, --c;

    mat[r][c] = who;
    ++cntRow[r][who];
    ++cntCol[c][who];

    if (!done && win(who)) {
      cout << i << " " << who << '\n';
      done = 1;
    }
  }

  if (!done) {
    cout << "Empate\n";
  }

  return 0;
}