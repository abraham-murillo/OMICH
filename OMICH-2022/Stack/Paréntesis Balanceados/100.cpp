#include <bits/stdc++.h>
using namespace std;

// Este problema se resuelve igual que paréntesis, lo único que hay que considerar son que tenemos diferentes tipos de caracteres entonces tenemos que
// buscar su pareja () [] {}, si no lo es, no está balanceado y no nos sirve

char inverse(char c) {
  if (c == '(')
    return ')';
  if (c == ')')
    return '(';
  if (c == '{')
    return '}';
  if (c == '}')
    return '{';
  if (c == '[')
    return ']';
  if (c == ']')
    return '[';
  return '?';
}

bool open(char c) {
  if (c == '(')
    return 1;
  if (c == '[')
    return 1;
  if (c == '{')
    return 1;
  return 0;
}

string s;

bool isGood() {
  stack<char> balance;

  for (char c : s) {
    if (open(c)) {
      balance.push(c);
    } else {
      if (balance.empty())
        return false;
      if (inverse(balance.top()) != c)
        return false;
      balance.pop();
    }
  }

  return balance.empty();
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int t;
  cin >> t;

  while (cin >> s) {
    cout << (isGood() ? "SI" : "NO") << '\n';
  }

  return 0;
}