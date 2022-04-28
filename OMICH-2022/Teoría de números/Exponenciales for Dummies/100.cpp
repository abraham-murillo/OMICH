#include <iostream>
using namespace std;

const int M = 1000007;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  unsigned long long a, b;
  cin >> a >> b;

  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans *= a;
      ans %= M;
    }
    a *= a;
    a %= M;
    b >>= 1;
  }

  cout << ans << '\n';

  return 0;
}