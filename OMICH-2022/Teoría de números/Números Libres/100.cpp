#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i < r; i++)
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define pb push_back

using ld = long double;
using lli = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int N = 1e6 + 5;
bitset<N> isPrime;
vector<int> primes;

void sieve() {
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i * i < N; ++i)
    if (isPrime[i])
      for (int j = i * i; j < N; j += i)
        isPrime[j] = 0;
  fore (i, 2, N)
    if (isPrime[i])
      primes.pb(i);
}

map<lli, int> factorize(lli n) {
  map<lli, int> cnt;
  for (auto p : primes) {
    if (p > n)
      break;
    while (n % p == 0) {
      cnt[p]++;
      n /= p;
    }
  }
  if (n > 1)
    cnt[n]++;
  return cnt;
}

bool isSquareFree(lli x) {
  for (auto p : primes) {
    lli p2 = 1LL * p * p;

    if (p2 > x)
      break;
    if (x % p2 == 0)
      return false;
  }
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  sieve();

  int n;
  cin >> n;

  fore (i, 0, n) {
    lli a, b;
    cin >> a >> b;

    // Es necesario hacer los 60 puntos para darse cuenta de esto
    bool squareFree = gcd(a, b) == 1;
    cout << (squareFree ? "SI" : "NO") << '\n';
  }

  return 0;
}
