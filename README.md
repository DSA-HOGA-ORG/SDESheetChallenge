# Striver's SDE 45-Day Challenge

## Structure

```
.
├── main.py                 # entry point — imports solutions & runs LeetCode test cases
├── ArraysI/                # topic folder (one per sheet section)
│   ├── __init__.py
│   └── set_matrix_zeroes.py   # solution + test_cases for the problem
├── logs/
│   └── daily_log.md        # per-day structured logbook
└── .github/workflows/
    └── daily-commit.yml    # auto commits + pushes every day
```

## Workflow

1. Tell opencode the **problem name** (e.g. "Set Matrix Zeroes") and the **language**
   (python / cpp / ...). It will:
   - create a placeholder file in the right topic folder
   - import it in `main.py` (via `KNOWN_PROBLEMS`)
   - log the problem in `logs/daily_log.md`
2. Fill in the solution, then run: `python main.py <problem-name>`
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