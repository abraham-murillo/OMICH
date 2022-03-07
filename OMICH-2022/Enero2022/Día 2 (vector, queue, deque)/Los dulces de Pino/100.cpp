#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n, m;
  while (cin >> n >> m) {
    queue<int> boxes;
    fore (i, 0, n) {
      int x;
      cin >> x;
      boxes.push(x);
    }

    queue<int> candies;
    fore (i, 0, m) {
      int x;
      cin >> x;
      candies.push(x);
    }

    long long waste = 0;
    while (!boxes.empty() && !candies.empty()) {
      if (candies.front() < boxes.front()) {
        waste += candies.front();
        candies.pop();
      } else {
        candies.front() -= boxes.front();
        boxes.pop();
      }
    }

    while (!candies.empty()) {
      waste += candies.front();
      candies.pop();
    }

    cout << waste << '\n';
  }

  return 0;
}