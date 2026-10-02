#include <bits/stdc++.h>
using namespace std;

namespace single_element_sorted {

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    // write your code here
    int n = nums.size();

    int low = 0, high = n - 1;

    while (low < high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] != nums[mid ^ 1])
        high = mid;

      else
        low = mid + 1;
    }

    return nums[low];
  }
};

} // namespace single_element_sorted
