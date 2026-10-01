/*
 * Striver's 45-Day Challenge (180 SDE Problems) — C++ Test Runner
 *
 * Mirrors main.py for C++ solutions.
 *
 * Usage:
 *   g++ -std=c++17 main.cpp -o main
 *   ./main <problem-name>        run one problem
 *   ./main                       run all registered problems
 *
 * Each problem file (e.g. ArraysI/set_matrix_zeroes.cpp) contains ONLY the
 * LeetCode Solution class inside a namespace. All test cases live here in
 * main.cpp inside the `run_<slug>` function.
 */

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

static int g_failures = 0;

void check_case(bool ok, const std::string& label) {
    if (ok) {
        std::cout << "  [PASS] " << label << "\n";
    } else {
        std::cout << "  [FAIL] " << label << "\n";
        ++g_failures;
    }
}

// ---- solution includes (pure Solution classes) ----
#include "Arrays/LinearScan/MaximumProductSubarray.cpp"
#include "Arrays/TwoPointers/SortColors.cpp"
#include "Arrays/TwoPointers/ThreeSum.cpp"
#include "Arrays/TwoPointers/NextPermutation.cpp"
#include "Arrays/TwoPointers/FourSum.cpp"
#include "Arrays/TwoPointers/MergeSortedArray.cpp"
#include "Arrays/TwoPointers/TrappingRainWater.cpp"
#include "Arrays/DivideAndConquer/CountInversion.cpp"
#include "Arrays/DivideAndConquer/ReversePairs.cpp"
#include "Hashing/HashingAndPrefixSums/TwoSum.cpp"
#include "Hashing/HashingAndPrefixSums/LongestConsecutiveSequence.cpp"
#include "Hashing/HashingAndPrefixSums/SubarraySumEqualsK.cpp"
#include "Hashing/HashingAndPrefixSums/LongestSubarrayWithSumK.cpp"
#include "DailyLeetCodeChallenge/September/CheckIfThereIsAValidParenthesesStringPath.cpp"
#include "BinarySearch/BinarySearch/FindPeakElement.cpp"
#include "BinarySearch/BinarySearch/FindMinInRotatedSortedArray.cpp"
#include "BinarySearch/BinarySearch/SearchInRotatedSortedArrayII.cpp"

// ---- test runners (test cases live here) ----
void run_count_inversions() {
    vector<int> t1{2, 4, 1, 3, 5};
    vector<int> t2{2, 3, 4, 5, 6};
    vector<int> t3{10, 10, 10};
    check_case(count_inversions::inversionCount(t1) == 3, "test 1");
    check_case(count_inversions::inversionCount(t2) == 0, "test 2");
    check_case(count_inversions::inversionCount(t3) == 0, "test 3");
}

void run_trapping_rain_water() {
    trapping_rain_water::Solution s;
    vector<int> t1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> t2{4, 2, 0, 3, 2, 5};
    vector<int> t3{2, 0, 2};
    check_case(s.trap(t1) == 6, "test 1");
    check_case(s.trap(t2) == 9, "test 2");
    check_case(s.trap(t3) == 2, "test 3");
}

void run_merge_sorted_array() {
    merge_sorted_array::Solution s;
    vector<int> t1{1, 2, 3, 0, 0, 0}; vector<int> n1{2, 5, 6};
    vector<int> t2{1};                 vector<int> n2{};
    vector<int> t3{0};                 vector<int> n3{1};
    s.merge(t1, 3, n1, 3); check_case(t1 == (vector<int>{1, 2, 2, 3, 5, 6}), "test 1");
    s.merge(t2, 1, n2, 0); check_case(t2 == (vector<int>{1}), "test 2");
    s.merge(t3, 0, n3, 1); check_case(t3 == (vector<int>{1}), "test 3");
}

void run_four_sum() {
    four_sum::Solution s;
    vector<int> t1{1, 0, -1, 0, -2, 2};
    check_case(s.fourSum(t1, 0) == (vector<vector<int>>{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}), "test 1");
    vector<int> t2{2, 2, 2, 2, 2};
    check_case(s.fourSum(t2, 8) == (vector<vector<int>>{{2, 2, 2, 2}}), "test 2");
}

void run_next_permutation() {
    next_permutation::Solution s;
    vector<int> t1{1, 2, 3};
    vector<int> t2{3, 2, 1};
    vector<int> t3{1, 1, 5};
    vector<int> t4{1};
    s.nextPermutation(t1); check_case(t1 == (vector<int>{1, 3, 2}), "test 1");
    s.nextPermutation(t2); check_case(t2 == (vector<int>{1, 2, 3}), "test 2");
    s.nextPermutation(t3); check_case(t3 == (vector<int>{1, 5, 1}), "test 3");
    s.nextPermutation(t4); check_case(t4 == (vector<int>{1}), "test 4");
}

void run_three_sum() {
    three_sum::Solution s;
    vector<int> t1{-1, 0, 1, 2, -1, -4};
    check_case(s.threeSum(t1) == (vector<vector<int>>{{-1, -1, 2}, {-1, 0, 1}}), "test 1");
    vector<int> t2{0, 1, 1};
    check_case(s.threeSum(t2) == (vector<vector<int>>{}), "test 2");
    vector<int> t3{0, 0, 0};
    check_case(s.threeSum(t3) == (vector<vector<int>>{{0, 0, 0}}), "test 3");
}

void run_sort_colors() {
    sort_colors::Solution s;
    vector<int> t1{2, 0, 2, 1, 1, 0};
    vector<int> t2{2, 0, 1};
    vector<int> t3{0};
    vector<int> t4{1, 0};
    s.sortColors(t1); check_case(t1 == (vector<int>{0, 0, 1, 1, 2, 2}), "test 1");
    s.sortColors(t2); check_case(t2 == (vector<int>{0, 1, 2}), "test 2");
    s.sortColors(t3); check_case(t3 == (vector<int>{0}), "test 3");
    s.sortColors(t4); check_case(t4 == (vector<int>{0, 1}), "test 4");
}

void run_maximum_product_subarray() {
    maximum_product_subarray::Solution s;
    vector<int> t1{2, 3, -2, 4};
    vector<int> t2{-2, 0, -1};
    vector<int> t3{-2};
    vector<int> t4{0, 2};
    vector<int> t5{-2, 3, -4};
    vector<int> t6{2, -5, 3, 1, -4, 0, -10, 2, 8};
    check_case(s.maxProduct(t1) == 6, "test 1");
    check_case(s.maxProduct(t2) == 0, "test 2");
    check_case(s.maxProduct(t3) == -2, "test 3");
    check_case(s.maxProduct(t4) == 2, "test 4");
    check_case(s.maxProduct(t5) == 24, "test 5");
    check_case(s.maxProduct(t6) == 120, "test 6");
}

void run_two_sum() {
    two_sum::Solution s;
    vector<int> t1{2, 7, 11, 15};
    vector<int> t2{3, 2, 4};
    vector<int> t3{3, 3};
    check_case(s.twoSum(t1, 9) == (vector<int>{0, 1}), "test 1");
    check_case(s.twoSum(t2, 6) == (vector<int>{1, 2}), "test 2");
    check_case(s.twoSum(t3, 6) == (vector<int>{0, 1}), "test 3");
}

void run_longest_consecutive() {
    longest_consecutive::Solution s;
    vector<int> t1{100, 4, 200, 1, 3, 2};
    vector<int> t2{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> t3{};
    vector<int> t4{1, 1, 1};
    check_case(s.longestConsecutive(t1) == 4, "test 1");
    check_case(s.longestConsecutive(t2) == 9, "test 2");
    check_case(s.longestConsecutive(t3) == 0, "test 3");
    check_case(s.longestConsecutive(t4) == 1, "test 4");
}

void run_reverse_pairs() {
    reverse_pairs::Solution s;
    vector<int> t1{1, 3, 2, 3, 1};
    vector<int> t2{2, 4, 3, 5, 1};
    vector<int> t3{5, 4, 3, 2, 1};
    vector<int> t4{1, 2, 3, 4, 5};
    check_case(s.reversePairs(t1) == 2, "test 1");
    check_case(s.reversePairs(t2) == 3, "test 2");
    check_case(s.reversePairs(t3) == 4, "test 3");
    check_case(s.reversePairs(t4) == 0, "test 4");
}

void run_subarray_sum_equals_k() {
    subarray_sum_equals_k::Solution s;
    vector<int> t1{1, 1, 1};
    vector<int> t2{1, 2, 3};
    vector<int> t3{1, -1, 0};
    vector<int> t4{3, 4, 7, 2, -3, 1, 4, 2};
    check_case(s.subarraySum(t1, 2) == 2, "test 1");
    check_case(s.subarraySum(t2, 3) == 2, "test 2");
    check_case(s.subarraySum(t3, 0) == 3, "test 3");
    check_case(s.subarraySum(t4, 7) == 4, "test 4");
}

void run_longest_subarray_with_sum_k() {
    longest_subarray_with_sum_k::Solution s;
    vector<int> t1{10, 5, 2, 7, 1, 9, 8, 5, 5, 4};
    vector<int> t2{1, 2, 3, 1, 1, 1, 1};
    vector<int> t3{4, -1, -2, 3, -2};
    vector<int> t4{-1, -4, -4, 3, 5, 0};
    vector<int> t5{5, 0, 1, 3, -3, 3, -5};
    check_case(s.longestSubarray(t1, 15) == 4, "test 1");
    check_case(s.longestSubarray(t2, 3) == 3, "test 2");
    check_case(s.longestSubarray(t3, -2) == 4, "test 3");
    check_case(s.longestSubarray(t4, 0) == 5, "test 4");
    check_case(s.longestSubarray(t5, 1) == 4, "test 5");
}

void run_check_if_valid_parentheses_path() {
    valid_parentheses_path::Solution s1;
    vector<vector<char>> t1{{'(', '(', '('}, {')', '(', ')'}, {'(', '(', ')'}, {'(', '(', ')'}};
    check_case(s1.hasValidPath(t1), "test 1 (4x3, path exists)");

    valid_parentheses_path::Solution s2;
    vector<vector<char>> t2{{')', ')'}, {'(', '('}};
    check_case(!s2.hasValidPath(t2), "test 2 (2x2, no path)");

    valid_parentheses_path::Solution s3;
    vector<vector<char>> t3{{'('}, {')'}};
    check_case(s3.hasValidPath(t3), "test 3 (2x1, \"()\")");

    valid_parentheses_path::Solution s4;
    vector<vector<char>> t4{{'('}};
    check_case(!s4.hasValidPath(t4), "test 4 (1x1, odd length)");

    valid_parentheses_path::Solution s5;
    vector<vector<char>> t5{{')', '('}, {'(', ')'}};
    check_case(!s5.hasValidPath(t5), "test 5 (2x2, bad start)");

    valid_parentheses_path::Solution s6;
    vector<vector<char>> t6{{'(', '(', ')'}, {')', ')', ')'}};
    check_case(s6.hasValidPath(t6), "test 6 (2x3, \"(())\")");

    valid_parentheses_path::Solution s7;
    vector<vector<char>> t7{{'(', ')'}, {'(', ')'}};
    check_case(!s7.hasValidPath(t7), "test 7 (2x2, odd path length)");
}

void run_find_peak_element() {
    find_peak_element::Solution s;
    vector<int> t1{1, 2, 3, 1};
    vector<int> t2{1, 2, 1, 3, 5, 6, 4};
    vector<int> t3{1};
    vector<int> t4{1, 2};
    vector<int> t5{2, 1};
    check_case(s.findPeakElement(t1) == 2, "test 1");
    check_case(s.findPeakElement(t2) == 1 || s.findPeakElement(t2) == 5, "test 2 (1 or 5)");
    check_case(s.findPeakElement(t3) == 0, "test 3");
    check_case(s.findPeakElement(t4) == 1, "test 4");
    check_case(s.findPeakElement(t5) == 0, "test 5");
}

void run_find_min_rotated() {
    find_min_rotated::Solution s;
    vector<int> t1{3, 4, 5, 1, 2};
    vector<int> t2{4, 5, 6, 7, 0, 1, 2};
    vector<int> t3{11, 13, 15, 17};
    vector<int> t4{1};
    vector<int> t5{2, 1};
    vector<int> t6{1, 2, 3, 4, 5};
    check_case(s.findMin(t1) == 1, "test 1");
    check_case(s.findMin(t2) == 0, "test 2");
    check_case(s.findMin(t3) == 11, "test 3 (not rotated)");
    check_case(s.findMin(t4) == 1, "test 4 (single element)");
    check_case(s.findMin(t5) == 1, "test 5");
    check_case(s.findMin(t6) == 1, "test 6 (already sorted)");
}

void run_search_rotated_ii() {
    search_rotated_ii::Solution s;
    vector<int> t1{2, 5, 6, 0, 0, 1, 2};
    vector<int> t2{2, 5, 6, 0, 0, 1, 2};
    vector<int> t3{1, 0, 1, 1, 1};
    vector<int> t4{1, 1, 1, 1, 1};
    vector<int> t5{1};
    vector<int> t6{3, 1};
    check_case(s.search(t1, 0), "test 1 (target 0 present)");
    check_case(!s.search(t2, 3), "test 2 (target 3 absent)");
    check_case(s.search(t3, 0), "test 3 (target 0 present)");
    check_case(!s.search(t4, 2), "test 4 (all equal, target absent)");
    check_case(!s.search(t5, 0), "test 5 (single element)");
    check_case(s.search(t6, 1), "test 6 (target 1 present)");
}

// slug -> test function
static const std::map<std::string, std::function<void()>> PROBLEMS = {
    {"maximum-product-subarray", run_maximum_product_subarray},
    {"sort-colors", run_sort_colors},
    {"three-sum", run_three_sum},
    {"next-permutation", run_next_permutation},
    {"four-sum", run_four_sum},
    {"merge-sorted-array", run_merge_sorted_array},
    {"trapping-rain-water", run_trapping_rain_water},
    {"count-inversions", run_count_inversions},
    {"two-sum", run_two_sum},
    {"longest-consecutive-sequence", run_longest_consecutive},
    {"reverse-pairs", run_reverse_pairs},
    {"subarray-sum-equals-k", run_subarray_sum_equals_k},
    {"longest-subarray-with-sum-k", run_longest_subarray_with_sum_k},
    {"check-if-there-is-a-valid-parentheses-string-path", run_check_if_valid_parentheses_path},
    {"find-peak-element", run_find_peak_element},
    {"find-minimum-in-rotated-sorted-array", run_find_min_rotated},
    {"search-in-rotated-sorted-array-ii", run_search_rotated_ii},
};

void run_problem(const std::string& slug) {
    auto it = PROBLEMS.find(slug);
    if (it == PROBLEMS.end()) {
        std::cerr << "[!] Unknown problem '" << slug << "'. Registered:\n";
        for (const auto& [k, v] : PROBLEMS) {
            std::cerr << "    - " << k << "\n";
        }
        return;
    }
    g_failures = 0;
    std::cout << "\n=== " << slug << " ===\n";
    it->second();
    std::cout << slug << (g_failures == 0 ? ": all passed\n" : ": FAILED\n");
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        run_problem(argv[1]);
        return g_failures == 0 ? 0 : 1;
    }

    if (PROBLEMS.empty()) {
        std::cout << "No problems registered yet. Ask opencode to add the first one.\n";
        return 0;
    }

    int total = 0;
    for (const auto& [slug, fn] : PROBLEMS) {
        run_problem(slug);
        total += g_failures;
    }
    return total == 0 ? 0 : 1;
}