#include <bits/stdc++.h>
using namespace std;

namespace trapping_rain_water {

class Solution {
public:
    int trap(const std::vector<int>& height) {
        if (height.empty()) return 0;

        int l = 0, r = height.size() - 1;

        int left_max = 0, right_max = 0, total_water = 0;

        while (l < r) {
            int h_left = height[l], h_right = height[r];

            if (h_left < h_right) {
                if (h_left >= left_max) {
                    left_max = h_left;
                } else {
                    total_water += left_max - h_left;
                }
                l++;
            } else {
                if (h_right >= right_max) {
                    right_max = h_right;
                } else {
                    total_water += right_max - h_right;
                }
                r--;
            }
        }

        return total_water;
    }
};

} // namespace trapping_rain_water