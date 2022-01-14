#include "recuerdame.h"

#include <bits/stdc++.h>
using namespace std;

set<int> st;

void recuerdame(int x) {
  st.insert(x);
}

bool soy(int x) {
  return st.count(x);
}