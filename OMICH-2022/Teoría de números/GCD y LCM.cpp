#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return 1LL * a * b / gcd(a, b);
}

/*
gcd(5, 15)
gcd(15, 5)
gcd(5, 15%5 = 0) -> gcd(5, 0)


gcd(1235000000, 650)
gcd(1235, 650)
gcd(650, 1235 % 650 = 585) -> gcd(650, 585)
gcd(585, 650 % 585 = 65) -> gcd(585, 65)
gcd(65, 0) => 65

gcd(x, 0) => x
gcd(a, b, c) => gcd(gcd(a, b), c) o gdc(a, gcd(b, c))
*/

int main() {
}