# AGENTS.md — Rules for opencode in this repo

## Never write the solution yourself

The user writes every solution. Do NOT implement, refactor, "fix", rename methods,
or rewrite a LeetCode solution unless the user explicitly asks in that message.

When the user pastes a `class Solution { ... }` block:

1. Save it **verbatim** as the problem file — only wrapping it in the repo's
   `namespace <slug> { ... }` and `using namespace std;` header, and leaving the
   user's whitespace, comments and variable names alone.
2. Register it in `main.cpp` (`#include` + `run_<slug>()` test cases + `PROBLEMS`
   entry) or `main.py` (`KNOWN_PROBLEMS` + `TEST_CASES`).
3. Add the log entry in `logs/daily_log.md` (SDE sheet problems) or
   `DailyLeetCodeChallenge/logs/daily_log.md` (daily LeetCode problems).
4. Build and run the matching runner so the tests actually pass.

Never volunteer an alternative approach or a fresh implementation for a problem
the user has not written yet. If the pasted code looks wrong, say so in one line
and let them decide — do not silently edit it.

## Other conventions

- One language per problem. Problem files are pure `Solution` classes; every test
  case lives in `main.py` / `main.cpp` only.
- SDE sheet solutions go in `Topic/Subtopic/ProblemName.cpp`, PascalCase.
- Daily LeetCode solutions go in `DailyLeetCodeChallenge/<Month>/ProblemName.cpp`.
- Method name must match LeetCode exactly (e.g. `singleNonDuplicate`, not
  `findSingle`).
- Append log days at the bottom, keep the most recent day last, and update the
  counters at the top of the log every time.
- Never commit or push unless the user asks.