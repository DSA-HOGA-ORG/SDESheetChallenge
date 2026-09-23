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

// ---- test runners (test cases live here) ----
void run_maximum_product_subarray() {
    Solution s;
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