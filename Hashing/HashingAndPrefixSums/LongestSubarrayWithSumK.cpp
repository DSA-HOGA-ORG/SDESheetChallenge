#include <bits/stdc++.h>
using namespace std;

namespace longest_subarray_with_sum_k {

class Solution {
public:
  long long longestSubarray(vector<int> &nums, int k) {
    map<long long, int> preSum;

    int maxLen = 0;
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];

      if (sum == k) {
        maxLen = max(maxLen, i + 1);
      }

      int rem = sum - k;
      if (preSum.find(rem) != preSum.end()) {
        int len = i - preSum[rem];
        maxLen = max(maxLen, len);
      }

      // keep the EARLIEST index of each prefix sum so i - preSum[rem] is maximal
      if (preSum.find(sum) == preSum.end()) {
        preSum[sum] = i;
      }
    }

    return maxLen;
  }
};

} // namespace longest_subarray_with_sum_k