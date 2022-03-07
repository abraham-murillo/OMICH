#include <iostream>

using namespace std;

int main() {
  long p;
  long n;
  cin >> p;
  cin >> n;
  long a[n];
  long f[p];
  for (long i = 1; i <= p; i++) {
    f[i] = 0;
  }
  for (long i = 1; i <= n; i++) {
    cin >> a[i];
    f[a[i]]++;
  }
  for (long i = 1; i <= p; i++) {
    cout << f[i] << endl;
  }
}