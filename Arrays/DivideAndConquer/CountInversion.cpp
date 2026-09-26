#include <bits/stdc++.h>
using namespace std;

namespace count_inversions {

int inversionCount(vector<int> &arr) {
  int i = 0;
  int count = 0;
  while (i < arr.size()) {
    int j = i + 1;

    while (j < arr.size()) {
      if (arr[i] > arr[j]) {
        count++;
      }
      j++;
    }
    i++;
  }
  return count;
}

} // namespace count_inversions
