#include <bits/stdc++.h>
using namespace std;

namespace longest_consecutive {

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int x : st) {
            if (st.find(x - 1) == st.end()) {
                int length = 1;

                while (st.find(x + length) != st.end()) {
                    length++;
                }

                longest = max(length, longest);
            }
        }
        return longest;
    }
};

} // namespace longest_consecutive