#include <bits/stdc++.h>
using namespace std;

namespace find_peak_element {

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();        
        int low = 0, high = n - 1;

        while(low < high){
            int mid  = low + (high - low) / 2;

            if(nums[mid] < nums[mid + 1])
                low = mid  + 1;
            
            else 
                high = mid; 

        }
        return low;
    }
};

} // namespace find_peak_element
