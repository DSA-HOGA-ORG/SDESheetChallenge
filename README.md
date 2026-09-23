# Striver's SDE 45-Day Challenge

## Structure

```
.
├── main.py                 # Python runner — solutions imported, test cases live here
├── main.cpp                # C++ runner — solutions included, test cases live here
├── ArraysI/                # topic folder (one per sheet section)
│   ├── __init__.py
│   └── SetMatrixZeroes.py  # pure LeetCode Solution class only
├── logs/
│   └── daily_log.md        # per-day structured logbook
└── .github/workflows/
    └── daily-commit.yml    # auto commits + pushes every day
```

## Principles

- **One language per problem.** A problem is solved in Python *or* C++, never both.
- **Problem files are pure solutions** — just the LeetCode `Solution` class, exactly
  the shape you'd submit. No test cases, no runner code.
- **All test cases live in `main.py` / `main.cpp` only.**

## Workflow

1. Tell opencode the **problem name**, **language** (python / cpp), and the
   **method name**. It will:
   - create the solution file in the right topic folder with only the `Solution` class
   - add an entry to `KNOWN_PROBLEMS` + `TEST_CASES` in `main.py` (or the equivalent
     in `main.cpp` for C++)
   - log the problem in `logs/daily_log.md`
2. Fill in the solution, then run the matching runner.
3. Commit + push daily — done automatically by the GitHub Actions workflow.

### main.py

Register the problem and put its test cases here:

```python
# ("topic_folder", "module_name", "method_name")
KNOWN_PROBLEMS = {
    "set-matrix-zeroes": ("ArraysI", "SetMatrixZeroes", "setZeroes"),
}

# (input_args_tuple, expected_output)
TEST_CASES = {
    "set-matrix-zeroes": [
        (([[1, 1, 1], [1, 0, 1], [1, 1, 1]],), [[1, 0, 1], [0, 0, 0], [1, 0, 1]]),
    ],
}
```

The solution file `ArraysI/SetMatrixZeroes.py` contains only:

```python
class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        ...
```

For in-place methods (`setZeroes` returns `None`), the runner compares the mutated
first argument against `expected`. Otherwise it compares the return value.

Run:

```sh
python main.py                     # all problems
python main.py set-matrix-zeroes   # one problem
```

### main.cpp

Test cases live in `main.cpp` as `run_<slug>()` functions; solution files contain only
the namespaced `Solution` class:

```cpp
// ArraysI/set_matrix_zeroes.cpp
namespace set_matrix_zeroes {
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { ... }
};
}
```

In `main.cpp` include the file and register the runner:

```cpp
#include "ArraysI/set_matrix_zeroes.cpp"

void run_set_matrix_zeroes() {
    set_matrix_zeroes::Solution s;
    vector<vector<int>> m = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    s.setZeroes(m);
    check_case(m == vector<vector<int>>{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}, "test 1");
}

PROBLEMS = {{"set-matrix-zeroes", run_set_matrix_zeroes}, ...};
```

Build and run:

```sh
g++ -std=c++17 main.cpp -o main
./main                      # run all problems
./main set-matrix-zeroes    # run one problem
```

## GitHub Actions

The `daily-commit.yml` workflow runs daily (18:30 UTC = midnight IST) and pushes any
uncommitted changes to `main`. No local `git push` needed — just work on your files;
GitHub handles the rest.

### First-time setup
1. Create the repo on GitHub, no README needed.
2. `git remote add origin git@github.com:DSA-HOGA-ORG/SDESheetChallenge.git`
3. `git push -u origin main`

For pushes to succeed in GitHub Actions, Actions must have **Write** permission:
Repo → Settings → Actions → General → Workflow permissions → "Read and write permissions".

## Regenerating the C++ binary

`./main`, `a.out`, `__pycache__/`, etc. are gitignored. Rebuild with
`g++ -std=c++17 main.cpp -o main`.
