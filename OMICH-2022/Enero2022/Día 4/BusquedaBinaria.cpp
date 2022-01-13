#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 
#endif

// n = 1e6, q = 1e6
                //0                  


bool existeConBinaria (int izq, int der, vector<int>& a, int val) {
  while (izq + 1 < der) {
    int mitad = (izq + der) / 2;
    if (a[mitad] < val) {
      izq = mitad;
    } else {
      der = mitad;
    }
  }
  
  return a[izq] == val || a[der] == val;
}

int primeraPosicion (int izq, int der, vector<int>& a, int val) {
  while (izq + 1 < der) {
    int mitad = (izq + der) / 2;
    if (a[mitad] < val) {
      izq = mitad;
    } else {
      der = mitad;
    }
  }
  
  if (a[izq] == val) {
    return izq;
  }

  if (a[der] == val) {
    return der;
  }

  return -1;
}


int ultimaPosicion (int izq, int der, vector<int>& a, int val) {
  while (izq + 1 < der) {
    int mitad = (izq + der) / 2;
    if (a[mitad] > val) {
      der = mitad;
    } else {
      izq = mitad;
    }
  }
  
  // izq, der
  if (a[der] == val) {
    return der;
  }

  if (a[izq] == val) {
    return izq;
  }

  return -1;
}


int cuantosHay (int izq, int der, vector<int> &a, int val) {
  if (existeConBinaria(izq, der, a, val) == false) {
    return 0;
  }
  return ultimaPosicion(izq, der, a, val) - primeraPosicion(izq, der, a, val) + 1;
}



int lowerBound (int izq, int der, vector<int>& a, int val) {
  while (izq + 1 < der) {
    int mitad = (izq + der) / 2;
    if (a[mitad] < val) {
      izq = mitad;
    } else {
      der = mitad;
    }
  }

  if (a[izq] >= val) {
    return a[izq];
  }

  if (a[der] >= val) {
    return a[der];
  }

  return 1e9 + 7;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  vector<int> a = {0, 1, 2, 2, 2, 4, 7, 7, 7, 9, 10};  // 7

  debug(*lower_bound(a.begin(), a.end(), 3)); // >=
  debug(*lower_bound(a.begin(), a.end(), 7));
  debug(*lower_bound(a.begin(), a.end(), 12));

  debug(*upper_bound(a.begin(), a.end(), 7));
  debug(upper_bound(a.begin(), a.end(), 2) - a.begin()); // > 
              // 0: {0, 0}
              // 1: {1, 1}
              // 2: {2, 4}
              // 4: {5, 5} 
              // 7: {6, 8}
              // 9: {9, 9}
              // 10: {10, 10}
  debug(lowerBound(0, a.size(), a, 3));
  debug(lowerBound(0, a.size(), a, 7));
  debug(lowerBound(0, a.size(), a, 12));
  debug("");

  debug(primeraPosicion(0, a.size(), a, 4));
  debug(primeraPosicion(0, a.size(), a, 7));
  debug(primeraPosicion(0, a.size(), a, 8));
  debug("");

  debug(ultimaPosicion(0, a.size(), a, 2));
  debug(ultimaPosicion(0, a.size(), a, 7));
  debug(ultimaPosicion(0, a.size(), a, 9));
  debug(ultimaPosicion(0, a.size(), a, 12));
  debug("");

  debug(cuantosHay(0, a.size() - 1, a, 0));
  debug(cuantosHay(0, a.size() - 1, a, 4));
  debug(cuantosHay(0, a.size() - 1, a, 7));
  debug(cuantosHay(0, a.size() - 1, a, 12));
  debug("");

  debug(existeConBinaria(0, a.size(), a, 7));
  debug(existeConBinaria(0, a.size(), a, 8));
  return 0;
}