# Striver's 180 SDE Sheet

## Structure

Mirrors the 180 SDE sheet. Problems live in `Topic/Subtopic/` folders; each file is a
pure LeetCode `Solution` class. All test cases live in `main.py` / `main.cpp` only.

```
.
├── main.py                 # Python runner — solutions imported, test cases here
├── main.cpp                # C++ runner — solutions included, test cases here
├── Arrays/
│   ├── LinearScan/
│   ├── TwoPointers/
│   └── DivideAndConquer/
├── Hashing/
│   └── HashingAndPrefixSums/
├── BinarySearch/
│   ├── BinarySearch/
│   ├── SearchOnAnswer/
│   └── PartitionSearch/
├── SlidingWindowAndTwoPointers/
│   ├── SlidingWindow/
│   └── CountingWindows/
├── RecursionAndBacktracking/
│   ├── SubsetsAndCombinations/
│   └── Backtracking/
├── LinkedList/
│   └── FastAndSlowPointers/
├── logs/
│   └── daily_log.md        # per-day structured logbook
└── .github/workflows/
    └── daily-commit.yml    # auto commits + pushes every day
```

## Principles

- **One language per problem.** A problem is solved in Python *or* C++, never both.
- **Problem files are pure solutions** — just the LeetCode `Solution` class.
- **All test cases live in `main.py` / `main.cpp` only.**

## Workflow

1. Tell opencode the **problem name**, **language** (python / cpp), and the
   **method name**. It will:
   - create the solution file in the right `Topic/Subtopic/` folder
   - add an entry to `KNOWN_PROBLEMS` + `TEST_CASES` in `main.py` (or the equivalent
     in `main.cpp` for C++)
   - log the problem in `logs/daily_log.md`
2. Fill in the solution, then run the matching runner.
3. Commit + push daily — done automatically by the GitHub Actions workflow.

### main.py

```python
# ("topic.subtopic", "module_name", "method_name")
KNOWN_PROBLEMS = {
    "set-matrix-zeroes": ("Arrays.LinearScan", "SetMatrixZeroes", "setZeroes"),
}

# (input_args_tuple, expected_output)
TEST_CASES = {
    "set-matrix-zeroes": [
        (([[1, 1, 1], [1, 0, 1], [1, 1, 1]],), [[1, 0, 1], [0, 0, 0], [1, 0, 1]]),
    ],
}
```

Solution file `Arrays/LinearScan/SetMatrixZeroes.py` contains only:

```python
class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        ...
```

For in-place methods (return `None`), the runner compares the mutated first argument
against `expected`. Otherwise it compares the return value.

Run:

```sh
python main.py                    # all problems
python main.py set-matrix-zeroes  # one problem
```

### main.cpp

Test cases live in `main.cpp` as `run_<slug>()` functions; solution files contain only
the namespaced `Solution` class. Register with `#include` + `PROBLEMS` map. See the
comments in `main.cpp`.

```sh
g++ -std=c++17 main.cpp -o main
./main                      # run all problems
./main set-matrix-zeroes    # run one problem
```

## GitHub Actions

The `daily-commit.yml` workflow runs daily (18:30 UTC = midnight IST) and pushes any
uncommitted changes to `main`. No local `git push` needed — just work on your files;
GitHub handles the rest.

When opening a new repo/org, make sure Actions has **Write** permission:
Repo → Settings → Actions → General → Workflow permissions → "Read and write permissions".

## Regenerating the C++ binary

`./main`, `a.out`, `__pycache__/`, etc. are gitignored. Rebuild with
`g++ -std=c++17 main.cpp -o main`.