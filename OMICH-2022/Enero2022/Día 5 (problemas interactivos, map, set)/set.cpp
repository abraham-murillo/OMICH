#include <bits/stdc++.h>
using namespace std;

#include "debug.h"
// {3, 4, 5, 8} <- set.lower_bound(4)

// red-black tree
// set <- conjunto
// map


struct orden {
  bool operator()(int x, int y) const {
    return x > y;
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  multiset<int> st;
  debug(st);
  st.insert(1);
  debug(st);
  st.insert(-1);
  debug(st);
  st.insert(8);
  debug(st);
  st.insert(5);
  debug(st);
  st.insert(19);
  debug(st);
  st.insert(19);
  debug(st);

  // st.erase(x);
  st.erase(st.find(19));
  debug(st);
  st.erase(6);
  debug(st);

  // st.count(x)
  debug(st.count(19));
  debug(st.count(20));

  // st.find(x), st.end()
  debug(st.find(19) != st.end());
  debug(st);
  debug(st.find(20) != st.end());



  debug(st.size());
  debug(st.empty());

  // auto it = st.lower_bound(18);
  // if (it == st.end()) {
  //   debug("No existe un número mayor o igual a 18");
  // } else {
  //   debug(*it);
  // }

  auto it = st.upper_bound(0);
  if (it == st.end()) {
    debug("No existe un número mayor a 19");
  } else {
    debug(*it);
  }

  // st.rend() st.begin() ... st.rbegin() st.end()
  for (auto it = st.rbegin(); it != st.rend(); it ++) {
    cout << *it << endl;
  }
  return 0;
}