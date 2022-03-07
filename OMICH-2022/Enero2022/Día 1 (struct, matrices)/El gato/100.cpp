#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

const int N = 50;

int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[] = {-1, 1, -1, 0, 1, -1, 0, 1};

char mat[N][N];
int n, m;

bool valid(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < n;
}

bool win(int r, int c, char who) {
  fore (i, 0, 8) {

    int total = 1;
    for (int sign : {-1, +1}) {

      int nr = r, nc = c;
      fore (it, 0, 3) {
        nr += sign * dr[i];
        nc += sign * dc[i];

        if (!valid(nr, nc))
          break;

        if (mat[nr][nc] != who)
          break;

        total++;
      }
    }

    if (total >= 3)
      return true;
  }

  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;

  cin >> m;
  fore (i, 0, n)
    fore (j, 0, n) {
      mat[i][j] = '.';
    }

  bool done = 0;
  fore (i, 1, m + 1) {
    int r, c;
    char who;
    cin >> r >> c >> who;
    --r, --c;

    mat[r][c] = who;

    if (!done && win(r, c, who)) {
      cout << i << " " << who << '\n';
      done = 1;
    }
  }

  if (!done) {
    cout << "Empate\n";
  }

  return 0;
}