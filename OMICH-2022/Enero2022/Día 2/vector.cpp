#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...)
#endif

int a[10];
vector<int> b;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  debug(b, b.size());

  // Agregar elementos O(10)
  b.push_back(1);
  b.push_back(2);
  b.push_back(3);

  // Conocer el tamaño
  debug(b, b.size());

  debug(b);

  // Eliminar elementos
  b.pop_back(); // Eliminar el último elemento O(1)

  b.push_back(4);
  b.push_back(5);
  b.push_back(6);
  debug(b);

  {
    // Eliminar el la posición i
    int i = 2;
    // Tener cuidado de que sí exista la posición O(K)
    b.erase(b.begin() + i);
    debug(b);
  }

  // Rango cerrado
  // [4, 10] -> 4, 5, 6, 7, 8, 9, 10
  // Rango abierto
  // [4, 10) -> 4, 5, 6, 7, 8, 9
  // (4, 10) -> 5, 6, 7, 8, 9
  // (3, 7] -> 4, 5, 6, 7
  // Rango infinito
  // (-inf, 10]
  // [10, inf)
  // Conjunto
  // [1, 3] + {5, 6} -> 1, 2, 3, 5, 6
  // [1, 3] + [5, 10] -> 1, 2, 3, 5, 6, 7, 8, 9, 10
  // [1, 3] + [2, 10] -> 1, 2, 3, 4, 5, ... 10

  {
    // Eliminar un rango [l,r]
    int l = 1, r = 3;

    // [inicio, fin)
    // [inicio, fin + 1) -> [inicio, fin]
    b.erase(b.begin() + l, b.begin() + r + 1);
    debug(b);
  }

  // Empty
  debug(b, b.empty());
  b.pop_back();
  debug(b, b.empty());

  // Inicializar elementos
  b = {1, 2, 3, 8, 9, 10};
  debug(b);

  {
    // Insertar un elemento en el vector
    int pos = 3, val = 6;
    b.insert(b.begin() + pos, val);
    debug(pos, val, b);
  }

  {
    // Insertar una lista de elementos
    int pos = 3;
    b.insert(b.begin() + pos, {4, 5});
    debug(pos, b);
  }

  // Acceder a cualquier posición
  {
    int pos = 3;
    a[pos] = 5;
    debug(a);
    b[pos] = 5;
    debug(b);
  }

  {
    // Acceder al último
    b[b.size() - 1] = 100; // Normal
    debug(b);

    b.back() = 200; // Cool
    debug(b);
  }

  {
    // Acceder al primero
    b[0] = 100;
    debug(b);

    b.front() = 200;
    debug(b);
  }

  // Imprimir un vector
  for (int i = 0; i < b.size(); i++)
    cout << b[i] << " ";
  cout << '\n';

  for (auto it : b)
    cout << it << " ";
  cout << '\n';

  // Para el futuro
  for (auto it = b.begin(); it != b.end(); it++)
    cout << *it << " ";
  cout << '\n';

  for (auto it = b.rbegin(); it != b.rend(); it++)
    cout << *it << " ";
  cout << '\n';

  return 0;
}
