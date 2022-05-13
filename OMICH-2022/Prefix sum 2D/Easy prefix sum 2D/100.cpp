#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<vector<int>> a(1001, vector<int>(1001, 0));
vector<vector<int>> prefixSum(1001, vector<int>(1001, 0));

int query(int r1, int c1, int r2, int c2)
{
    return prefixSum[r2][c2] - prefixSum[r1 - 1][c2] - prefixSum[r2][c1 - 1] + prefixSum[r1 - 1][c1 - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // Leemos dimensiones de la matriz
    int n, m;
    cin >> n >> m;
    // Leer matriz 
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= m; c++)
        {
            cin >> a[r][c]; // a
            prefixSum[r][c] = a[r][c] + prefixSum[r - 1][c] // suma lo de arriba
                              + prefixSum[r][c - 1]         // suma lo de la izquierda
                              - prefixSum[r - 1][c - 1]; // restas la diagonal
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int r1, c1, r2, c2; 
        cin >> r1 >> c1 >> r2 >> c2;
        cout << query(r1, c1, r2, c2) << endl;
    }
    return 0;
}