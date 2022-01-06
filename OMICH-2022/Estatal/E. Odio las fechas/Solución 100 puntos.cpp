#include <bits/stdc++.h>
using namespace std;

vector<int> diasPorMes{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool esBisiesto(int anyo) {
  return (anyo % 400 == 0) || (anyo % 100 != 0 && anyo % 4 == 0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int dia, mes, anyo;
  char c;
  // DD, MM, YY
  cin >> dia >> c >> mes >> c >> anyo;

  int k;
  cin >> k;

  while (k--) {
    dia++;
    if (esBisiesto(anyo) && mes == 2 && dia == 29) {
      continue;
    }
    if (dia > diasPorMes[mes]) {
      mes++;
      if (mes == 13) {
        anyo++;
        mes = dia = 1;
      } else {
        dia = 1;
      }
    }
  }

  cout << setw(2) << setfill('0') << dia << "/" << setw(2) << setfill('0') << mes << "/" << setw(2)
       << setfill('0') << anyo << '\n';

  return 0;
}