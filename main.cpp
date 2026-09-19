/*
 * Striver's SDE 45-Day Challenge — C++ Test Runner
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

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

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
// #include "ArraysI/set_matrix_zeroes.cpp"

// ---- test runners (test cases live here) ----
// void run_set_matrix_zeroes() {
//     set_matrix_zeroes::Solution s;
//     std::vector<std::vector<int>> m = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
//     s.setZeroes(m);
//     check_case(m == std::vector<std::vector<int>>{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}, "test 1");
// }

// slug -> test function
static const std::map<std::string, std::function<void()>> PROBLEMS = {
    // {"set-matrix-zeroes", run_set_matrix_zeroes},
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