#include <bits/stdc++.h>
using namespace std;

namespace next_permutation {

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size() - 1;
        int breakPoint = -1;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakPoint = i;
                break;
            }
        }

        if (breakPoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n; i > breakPoint; i--) {
            if (nums[i] > nums[breakPoint]) {
                swap(nums[i], nums[breakPoint]);
                break;
            }
        }

        int i = breakPoint + 1;
        int j = n;

        while (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};

} // namespace next_permutation