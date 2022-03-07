#include <bits/stdc++.h>

using namespace std;
#define fore(i, l, r) for (int i = l; i < r; i++)

struct Concursante {
  int pts = 0;
  int tens = 0;
  int xs = 0;

  bool operator==(const Concursante& c) const {
    return pts == c.pts && tens == c.tens && xs == c.xs;
  }

  bool operator>(const Concursante& c) const {
    if (pts != c.pts)
      return pts > c.pts;
    if (tens != c.tens)
      return tens > c.tens;
    return xs > c.xs;
  }
};

int score(string& x) {
  if (x == "M")
    return 0;
  if (x == "X")
    return 10;
  return stoi(x);
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n;
  string s;
  while (cin >> n) {
    Concursante job;
    fore (i, 0, n) {
      cin >> s;
      job.pts += score(s);
      job.tens += (s == "10" || s == "X");
      job.xs += (s == "X");
    }

    Concursante rob;
    fore (i, 0, n) {
      cin >> s;
      rob.pts += score(s);
      rob.tens += (s == "10" || s == "X");
      rob.xs += (s == "X");
    }

    if (rob == job) {
      cout << "Empate\n";
    } else {
      cout << (rob > job ? "Rob" : "Job") << '\n';
    }
  }

  return 0;
}
