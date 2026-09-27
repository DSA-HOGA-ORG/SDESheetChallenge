#include <bits/stdc++.h>
using namespace std;

namespace subarray_sum_equals_k {

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int preSum = 0, cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            int remove = preSum - k;

            if (mpp.find(remove) != mpp.end()) cnt += mpp[remove];

            mpp[preSum] += 1;
        }
        return cnt;
    }
};

} // namespace subarray_sum_equals_k