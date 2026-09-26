#include <bits/stdc++.h>
using namespace std;

namespace reverse_pairs {

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

    long long mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;

        int inv = (int)mergeSort(nums, l, m) + (int)mergeSort(nums, m + 1, r);

        int j = m + 1;
        for (int i = l; i <= m; i++) {
            while (j <= r && nums[i] > 2LL * nums[j]) j++;
            inv += (j - (m + 1));
        }

        inplace_merge(nums.begin() + l, nums.begin() + m + 1, nums.begin() + r + 1);

        return inv;
    }
};

} // namespace reverse_pairs