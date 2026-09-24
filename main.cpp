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

// ---- test runners (test cases live here) ----
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

// slug -> test function
static const std::map<std::string, std::function<void()>> PROBLEMS = {
    {"maximum-product-subarray", run_maximum_product_subarray},
    {"sort-colors", run_sort_colors},
    {"three-sum", run_three_sum},
    {"next-permutation", run_next_permutation},
    {"four-sum", run_four_sum},
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