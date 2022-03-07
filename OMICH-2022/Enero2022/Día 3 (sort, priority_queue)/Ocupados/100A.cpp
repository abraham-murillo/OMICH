#include <bits/stdc++.h>
using namespace std;

int countSwaps(vector<int>& arr, int desc) {
  int n = arr.size();

  vector<pair<int, int>> arrPos(n);
  for (int i = 0; i < n; i++) {
    arrPos[i].first = arr[i];
    arrPos[i].second = i;
  }
  sort(arrPos.begin(), arrPos.end());

  if (desc == 1) {
    reverse(arrPos.begin(), arrPos.end());
  }

  vector<bool> visited(n, false);
  int swaps = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] || arrPos[i].second == i)
      continue;

    int cycleSize = 0;
    int j = i;
    while (!visited[j]) {
      visited[j] = 1;
      j = arrPos[j].second;
      cycleSize++;
    }

    if (cycleSize > 0) {
      swaps += (cycleSize - 1);
    }
  }

  return swaps;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << min(countSwaps(arr, 0), countSwaps(arr, 1)) << '\n';

  return 0;
}