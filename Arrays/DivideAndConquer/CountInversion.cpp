#include <bits/stdc++.h>
using namespace std;

namespace count_inversions {

long long countAndMerge(vector<int>& arr, int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;

  vector<int> left(n1), right(n2);

  for (int i = 0; i < n1; i++)
    left[i] = arr[l + i];

  for (int j = 0; j < n2; j++)
    right[j] = arr[m + 1 + j];

  long long res = 0;
  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
      res += (n1 - i);
    }
  }

  while (i < n1)
    arr[k++] = left[i++];
  while (j < n2)
    arr[k++] = right[j++];

  return res;
}

long long countInv(vector<int>& arr, int l, int r) {
  if (l >= r) return 0;

  int m = l + (r - l) / 2;

  long long res = 0;
  res += countInv(arr, l, m);
  res += countInv(arr, m + 1, r);
  res += countAndMerge(arr, l, m, r);

  return res;
}

long long inversionCount(vector<int>& arr) {
  return countInv(arr, 0, (int)arr.size() - 1);
}

} // namespace count_inversions