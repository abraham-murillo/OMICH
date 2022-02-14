#include "PilaInteractivo.h"
#include <bits/stdc++.h>
using namespace std;

stack<int> s;

void agrega(int n) {
  s.push(n);
}

int saca() {
  if (s.empty()) {
    return -1;
  }

  int aux = s.top();
  s.pop();
  return aux;
}