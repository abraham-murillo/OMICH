#include <iostream>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int islas = 0;
  for (int i = 1; i < s.size() - 1; ++i)
    if (s[i] != s[i - 1] && s[i - 1] == s[i + 1])
      islas++;

  cout << islas << '\n';

  return 0;
}