#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n;
  string s;
  cin >> n >> s;

  int a, b, c;
  a = b = c = 0;
  for (char ch : s) {
    if (ch == 'a') {
      a++;
    }
    if (ch == 'b') {
      b++;
    }
    if (ch == 'c') {
      c++;
    }
  }

  cout << (a + b == c ? "SI" : "NO") << '\n';
  return 0;
}