"""
Striver's SDE 45-Day Challenge — Test Runner

Entry point for testing problem solutions against LeetCode test cases.

Usage:
    python main.py [problem-name]

Each problem file lives in its topic folder (e.g. ArraysI/,
ArraysII/, ...) and exposes a `Solution` class. When I ask opencode
to add a problem, it creates the placeholder file in the right topic
folder and imports it here along with its LeetCode test cases.
"""

import importlib
import sys

KNOWN_PROBLEMS = {
    # "problem-name": ("topic_folder", "module_name"),
    # e.g. "set-matrix-zeroes": ("ArraysI", "set_matrix_zeroes"),
}


def load_problem(key: str):
    topic, module = KNOWN_PROBLEMS[key]
    return importlib.import_module(f"{topic}.{module}")


def main():
    args = sys.argv[1:]
    if args:
        run_problem(args[0].strip().lower())
        return

    if not KNOWN_PROBLEMS:
        print("No problems registered yet. Ask opencode to add the first one.")
        return

    for key in KNOWN_PROBLEMS:
        run_problem(key)


def run_problem(key: str):
    try:
        mod = load_problem(key)
    except KeyError:
        print(f"[!] Unknown problem '{key}'. Registered: {list(KNOWN_PROBLEMS)}")
        return

    print(f"\n=== {key} ===")
    if not hasattr(mod, "test_cases"):
        print(f"[!] {key} has no test_cases defined.")
        return

    Solution = mod.Solution
    passed = 0
    for i, case in enumerate(mod.test_cases, 1):
        inp, expected = case
        got = Solution().solve(*inp)
        status = "PASS" if got == expected else "FAIL"
        if status == "FAIL":
            print(f"  [{i}] {status}  input={inp}  expected={expected}  got={got}")
        else:
            print(f"  [{i}] PASS")
        passed += status == "PASS"

    total = len(mod.test_cases)
    print(f"{key}: {passed}/{total} passed")


if __name__ == "__main__":
    main()