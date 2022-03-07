#include <bits/stdc++.h>
using namespace std;
#define fore(i, l, r) for (int i = l; i < r; i++)
#define foren(i, l, r) for (int i = l; i > r; i--)

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int a = 0, b = 0, c = 0, MayT = 0, times[6], Sum = 0;
  cin >> a >> b >> c;

  fore (i, 0, 6) {
    cin >> times[i];
    if (times[i] > MayT)
      MayT = times[i];
  }
  vector<int> Time(MayT + 1, 0);
  fore (i, times[0], times[1])
    Time[i]++;
  fore (i, times[2], times[3])
    Time[i]++;
  fore (i, times[4], times[5])
    Time[i]++;

  fore (i, 0, MayT + 1) {
    if (Time[i] == 1)
      Sum += a;
    else if (Time[i] == 2)
      Sum += b * 2;
    else if (Time[i] == 3)
      Sum += c * 3;
  }

  cout << Sum;

  return 0;
}