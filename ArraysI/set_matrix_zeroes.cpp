#include <bits/stdc++.h>
using namespace std;

// LeetCode problem: Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

namespace set_matrix_zeroes {

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // TODO: implement
    }
};

void tests() {
    Solution s;

    vector<vector<int>> m1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> e1 = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    s.setZeroes(m1);
    check_case(m1 == e1, "test 1");

    vector<vector<int>> m2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<vector<int>> e2 = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
    s.setZeroes(m2);
    check_case(m2 == e2, "test 2");
}

}  // namespace set_matrix_zeroes