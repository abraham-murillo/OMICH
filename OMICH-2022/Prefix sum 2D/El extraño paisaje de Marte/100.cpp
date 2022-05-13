#include <bits/stdc++.h>
#include "debug.h"
#define endl '\n'

using namespace std;

constexpr int N = 1005;

int grid[N][N];
int prefixSum[N][N][2];

int query(int r1, int c1, int r2, int c2, int color)
{
    return prefixSum[r2][c2][color] - prefixSum[r1 - 1][c2][color] - prefixSum[r2][c1 - 1][color] + prefixSum[r1 - 1][c1 - 1][color];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int d;
    cin >> d;
    for (int i = 0; i < d; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        c -= 'A';
        grid[x][y][c]++;    
    }
    for (int r = 1; r < N; r++)
    {
        for (int c = 1; c < N; c++)
        {
            for (int color = 0; color < 2; color++) {
                prefixSum[r][c][color] = grid[r][c][color] + prefixSum[r - 1][c][color]
                                + prefixSum[r][c - 1][color]
                                - prefixSum[r - 1][c - 1][color];
            }
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        int n, s, e, w;
        cin >> n >> s >> e >> w;
        cout << query(w, s, e, n, 0) << " " << query(w, s, e, n, 1) << endl;
    }
    return 0;
}