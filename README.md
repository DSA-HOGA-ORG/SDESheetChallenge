# Striver's SDE 45-Day Challenge

## Structure

```
.
├── main.py                 # Python runner — imports solutions & runs test cases
├── main.cpp                # C++ runner — includes solution files & runs test cases
├── ArraysI/                # topic folder (one per sheet section)
│   ├── __init__.py
│   ├── set_matrix_zeroes.py   # python solution + test_cases
│   └── set_matrix_zeroes.cpp  # cpp solution + tests()
├── logs/
│   └── daily_log.md        # per-day structured logbook
└── .github/workflows/
    └── daily-commit.yml    # auto commits + pushes every day
```

## Workflow

1. Tell opencode the **problem name** (e.g. "Set Matrix Zeroes") and the **language**
   (python / cpp / ...). It will:
   - create a placeholder file in the right topic folder (`.py` and/or `.cpp`)
   - register it in `main.py` (`KNOWN_PROBLEMS`) and/or `main.cpp` (`PROBLEMS`)
   - log the problem in `logs/daily_log.md`
2. Fill in the solution, then run the matching runner.
3. Commit + push daily — done automatically by the GitHub Actions workflow.

### main.py

Each problem file must expose:

```python
from typing import Any

class Solution:
    def solve(self, *args: Any) -> Any:
        ...

# (input_tuple, expected_output) pairs
test_cases = []
```

Add the mapping in `main.py`:

```python
KNOWN_PROBLEMS = {
    "set-matrix-zeroes": ("ArraysI", "set_matrix_zeroes"),
}
```

Then run `python main.py set-matrix-zeroes`.

### main.cpp

Each problem file (e.g. `ArraysI/set_matrix_zeroes.cpp`) lives in a namespace and exposes
a `tests()` function that uses the global `check_case(ok, label)` helper:

```cpp
namespace set_matrix_zeroes {
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { ... }
};
void tests() {
    Solution s;
    vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(m);
    check_case(m == vector<vector<int>>{{1,0,1},{0,0,0},{1,0,1}}, "test 1");
}
}  // namespace set_matrix_zeroes
```

Register it in `main.cpp` — include the file and add it to `PROBLEMS`:

```cpp
#include "ArraysI/set_matrix_zeroes.cpp"
PROBLEMS = {{"set-matrix-zeroes", set_matrix_zeroes::tests}, ...};
```

Then build and run:

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
1. Create the repo on GitHub (e.g. `SDESheetChallenge`), no README needed.
2. `git remote add origin git@github.com:shaunakmishra25/SDESheetChallenge.git`
3. `git push -u origin main`

For pushes to succeed in GitHub Actions, Actions must have **Write** permission:
Repo → Settings → Actions → General → Workflow permissions → "Read and write permissions".

## Regenerating the C++ binary

`./main`, `a.out`, `__pycache__/`, etc. are gitignored. Rebuild with
`g++ -std=c++17 main.cpp -o main`.