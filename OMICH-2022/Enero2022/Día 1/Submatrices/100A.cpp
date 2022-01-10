#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

using ii = pair<int, int>;

const int N = 1005;
int a[N][N], b[N][N];
bool ans[N][N];
ii dimA, dimB;

void paintSolution(int r, int c) {
  fore (dr, 0, dimB.first)
    fore (dc, 0, dimB.second) {
      ans[r + dr][c + dc] = 1;
    }
}

bool exists(int r, int c) {
  fore (dr, 0, dimB.first)
    fore (dc, 0, dimB.second)
      if (a[r + dr][c + dc] != b[dr][dc])
        return false;
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> dimA.first >> dimA.second;
  fore (r, 0, dimA.first)
    fore (c, 0, dimA.second) {
      cin >> a[r][c];
    }

  cin >> dimB.first >> dimB.second;
  fore (r, 0, dimB.first)
    fore (c, 0, dimB.second) {
      cin >> b[r][c];
    }

  fore (r, 0, dimA.first) {
    if (r + dimB.first - 1 >= dimA.first)
      break;

    fore (c, 0, dimA.second) {
      if (c + dimB.second - 1 >= dimA.second)
        break;

      if (a[r][c] == b[0][0] && exists(r, c)) {
        paintSolution(r, c);
      }
    }
  }

  fore (r, 0, dimA.first) {
    fore (c, 0, dimA.second) {
      cout << ans[r][c] << " ";
    }
    cout << '\n';
  }

  return 0;
}
