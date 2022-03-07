#include <iostream>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 1) {
      cout << i << '\n';
      break;
    }
  }

  return 0;
}