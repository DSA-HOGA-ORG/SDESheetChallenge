"""
Striver's SDE 45-Day Challenge — Test Runner

Entry point for testing problem solutions against LeetCode test cases.

Usage:
    python main.py [problem-name]

Each problem file lives in its topic folder (e.g. ArraysI/,
ArraysII/, ...) and contains ONLY the LeetCode `Solution` class.
All test cases are defined here in TEST_CASES.
"""

import copy
import importlib
import sys
from typing import Any

# "problem-name": ("topic_folder", "module_name", "method_name")
KNOWN_PROBLEMS = {
    "set-matrix-zeroes": ("ArraysI", "SetMatrixZeroes", "setZeroes"),
    "pascals-triangle": ("ArraysI", "PascalsTriangle", "generate"),
    "next-permutation": ("ArraysI", "NextPermutation", "nextPermutation"),
    "maximum-subarray-sum": ("ArraysI", "MaximumSubarraySum", "maxSubArray"),
    "sort-colors": ("ArraysI", "SortColors", "sortColors"),
    "best-time-to-buy-and-sell-stock": ("ArraysI", "BestTimeToBuyAndSellStock", "maxProfit"),
    "rotate-image": ("ArraysII", "RotateImage", "rotate"),
    "merge-intervals": ("ArraysII", "MergeIntervals", "merge"),
    "merge-sorted-array": ("ArraysII", "MergeSortedArray", "merge"),
}

# "problem-name": [(input_args_tuple, expected), ...]
TEST_CASES: dict[str, list[tuple[tuple[Any, ...], Any]]] = {
    "set-matrix-zeroes": [
        (([[1, 1, 1], [1, 0, 1], [1, 1, 1]],), [[1, 0, 1], [0, 0, 0], [1, 0, 1]]),
        (([[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]],), [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]),
    ],
    "pascals-triangle": [
        ((1,), [[1]]),
        ((5,), [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]),
    ],
    "next-permutation": [
        (([1, 2, 3],), [1, 3, 2]),
        (([3, 2, 1],), [1, 2, 3]),
        (([1, 1, 5],), [1, 5, 1]),
        (([1],), [1]),
    ],
    "maximum-subarray-sum": [
        (([-2, 1, -3, 4, -1, 2, 1, -5, 4],), 6),
        (([1],), 1),
        (([5, 4, -1, 7, 8],), 23),
        (([-1, -2, -3],), -1),
        (([8, -19, 5, -4, 20],), 21),
    ],
    "sort-colors": [
        (([2, 0, 2, 1, 1, 0],), [0, 0, 1, 1, 2, 2]),
        (([2, 0, 1],), [0, 1, 2]),
        (([0],), [0]),
        (([1, 0],), [0, 1]),
        (([2, 2, 0, 0, 1, 1],), [0, 0, 1, 1, 2, 2]),
    ],
    "best-time-to-buy-and-sell-stock": [
        (([7, 1, 5, 3, 6, 4],), 5),
        (([7, 6, 4, 3, 1],), 0),
        (([1],), 0),
        (([2, 4, 1],), 2),
        (([3, 3, 5, 0, 0, 3, 1, 4],), 4),
    ],
    "rotate-image": [
        (([[1, 2, 3], [4, 5, 6], [7, 8, 9]],), [[7, 4, 1], [8, 5, 2], [9, 6, 3]]),
        (([[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]],), [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]),
        (([[1]],), [[1]]),
        (([[1, 2], [3, 4]],), [[3, 1], [4, 2]]),
    ],
    "merge-intervals": [
        (([[1, 3], [2, 6], [8, 10], [15, 18]],), [[1, 6], [8, 10], [15, 18]]),
        (([[1, 4], [4, 5]],), [[1, 5]]),
        (([[1, 4], [2, 3]],), [[1, 4]]),
        (([[1, 4], [0, 2], [3, 5]],), [[0, 5]]),
        (([],), []),
        (([[1, 4]],), [[1, 4]]),
    ],
    "merge-sorted-array": [
        (([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3), [1, 2, 2, 3, 5, 6]),
        (([1], 1, [], 0), [1]),
        (([0], 0, [1], 1), [1]),
    ],
}


def load_problem(key: str):
    topic, module, _method = KNOWN_PROBLEMS[key]
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

    _, _, method = KNOWN_PROBLEMS[key]
    print(f"\n=== {key} ===")
    cases = TEST_CASES.get(key)
    if not cases:
        print(f"[!] {key} has no test cases in main.py.")
        return

    passed = 0
    for i, (inp, expected) in enumerate(cases, 1):
        call_args = copy.deepcopy(inp)
        got = getattr(mod.Solution(), method)(*call_args)
        # in-place methods return None — compare the mutated first argument
        actual = got if got is not None else call_args[0]
        status = "PASS" if actual == expected else "FAIL"
        if status == "FAIL":
            print(f"  [{i}] {status}  input={inp}  expected={expected}  got={actual}")
        else:
            print(f"  [{i}] PASS")
        passed += status == "PASS"

    print(f"{key}: {passed}/{len(cases)} passed")


if __name__ == "__main__":
    main()