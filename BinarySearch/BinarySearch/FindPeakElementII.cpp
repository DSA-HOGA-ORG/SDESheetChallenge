#include <bits/stdc++.h>
#include <cmath>
using namespace std;

namespace find_peak_element_ii {

class Solution {

private:
  int maxElement(vector<vector<int>> &mat, int m, int n, int col) {
    int maxValue = -1;
    int index = -1;

    for (int i = 0; i < n; i++) {
      if (mat[i][col] > maxValue) {
        maxValue = mat[i][col];
        index = i;
      }
    }

    return index;
  }

public:
  vector<int> findPeakGrid(vector<vector<int>> &mat) {
    // write your code here

    int n = mat.size(), m = mat[0].size();

    int low = 0, high = n - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      int row = maxElement(mat, m, n, mid);

      int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
      int right = mid + 1 < m ? mat[row][mid + 1] : -1;

      int val = mat[row][mid];

      if (val > left && val > right)
        return {row, mid};
      else if (val < left)
        high = mid - 1;
      else
        low = mid + 1;
    }

    return {-1, -1};
  }
};

} // namespace find_peak_element_ii
