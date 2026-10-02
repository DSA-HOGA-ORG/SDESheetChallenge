# Striver's 45-Day Challenge — Daily Log

> Total days: **10 / 45**
> Total problems solved: **21 / 180**

---

## Day 01 — Wednesday, 23 Sep 2026

**Topic:** Arrays
**Subtopic:** Linear Scan
**Problems solved:** 4 / 4
**Total time spent:** —

### Summary
Completed all 4 Linear Scan problems.

---

### Problem: Majority Element
- **Link:** [LeetCode](https://leetcode.com/problems/majority-element/) | [Solution](../Arrays/LinearScan/MajorityElementI.py)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Majority Element II
- **Link:** [LeetCode](https://leetcode.com/problems/majority-element-ii/) | [Solution](../Arrays/LinearScan/MajorityElementII.py)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Maximum Subarray Sum (Kadane's)
- **Link:** [LeetCode](https://leetcode.com/problems/maximum-subarray/) | [Solution](../Arrays/LinearScan/MaximumSubarraySum.py)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Maximum Product Subarray
- **Link:** [LeetCode](https://leetcode.com/problems/maximum-product-subarray/) | [Solution](../Arrays/LinearScan/MaximumProductSubarray.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

## Day 02 — Thursday, 24 Sep 2026

**Topic:** Arrays
**Subtopic:** Two Pointers
**Problems solved:** 4 / 4
**Total time spent:** —

### Summary
Completed all 4 Two Pointers problems.

---

### Problem: Sort Colors
- **Link:** [LeetCode](https://leetcode.com/problems/sort-colors/) | [Solution](../Arrays/TwoPointers/SortColors.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: 3 Sum
- **Link:** [LeetCode](https://leetcode.com/problems/3sum/) | [Solution](../Arrays/TwoPointers/ThreeSum.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Next Permutation
- **Link:** [LeetCode](https://leetcode.com/problems/next-permutation/) | [Solution](../Arrays/TwoPointers/NextPermutation.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: 4 Sum
- **Link:** [LeetCode](https://leetcode.com/problems/4sum/) | [Solution](../Arrays/TwoPointers/FourSum.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

<!--
HOW TO USE THIS LOG:
- Copy the daily block below for each new day and fill it in.
- Update the counters at the top every day.
- Append new days at the bottom, always keeping the most recent day last.

---
## Day 03 — <Day>, <Date>

**Topic:** —
**Subtopic:** —
**Problems solved:** 0
**Total time spent:** —

### Summary

### Problem: _Problem Name_
- **Link:** [LeetCode](https://leetcode.com/problems/) | [Solution](../<Topic>/<Subtopic>/)
- **Status:** ☐ Solved | ☐ Unsolved | ☐ Need Review
- **Time taken:** —
- **Approach:**
  - <!-- What technique/heuristic did you use? -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- Edge cases missed, syntax slips, wrong initial idea... -->
- **What I learned:**
  - <!-- Pattern recognized, takeaway -->
- **Next steps:**
  - <!-- Revisit blindly, try the follow-up, think of a new approach... -->
-->

---

## Day 06 — Tuesday, 29 Sep 2026

**Topic:** Binary Search
**Subtopic:** Binary Search (on the answer's monotonicity)
**Problems solved:** 1 / 1
**Total time spent:** —

### Summary
Solved Find Peak Element with the standard slope-based binary search on an
unsorted array.

---

### Problem: Find Peak Element
- **Link:** [LeetCode](https://leetcode.com/problems/find-peak-element/) | [Solution](../BinarySearch/BinarySearch/FindPeakElement.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - Compare `nums[mid]` with `nums[mid + 1]`: if ascending, a peak must exist to
    the right of `mid` → `low = mid + 1`; otherwise a peak exists at `mid` or to
    its left → `high = mid`
  - `low < high` with `low = high` as the exit, so `mid + 1` is always in range
  - Loop invariant: a peak always exists inside `[low, high]`
- **Complexity:** Time O(log n) / Space O(1)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Single Element in a Sorted Array (540)
- **Link:** [LeetCode](https://leetcode.com/problems/single-element-in-a-sorted-array/) | [Solution](../BinarySearch/BinarySearch/SingleElementInSortedArray.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - XOR trick for the pair partner: `mid ^ 1` flips only the last bit, so it
    returns `mid - 1` when `mid` is even and `mid + 1` when `mid` is odd — no
    parity branch needed
  - `nums[mid] != nums[mid ^ 1]` → the pair is broken here, so the single element
    is at `mid` or to its left → `high = mid`
  - Otherwise the pair is intact and the answer is strictly right → `low = mid + 1`
  - Loop invariant: the answer stays inside `[low, high]`
- **Complexity:** Time O(log n) / Space O(1)
- **Mistakes made:**
  - Wrote `class solution` / `singlenonduplicate` in lowercase — renamed to
    `Solution` / `singleNonDuplicate` to match LeetCode
- **What I learned:**
  - `mid ^ 1` is a cleaner way to reach a pair partner than an `if (mid % 2)` fix-up
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Search a 2D Matrix II (240)
- **Link:** [LeetCode](https://leetcode.com/problems/search-a-2d-matrix-ii/) | [Solution](../BinarySearch/BinarySearch/Search2DMatrixII.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - Staircase search from the top-right corner: rows ascend, columns descend
  - `matrix[row][col] < target` → everything left in this row is smaller → `row++`
  - `matrix[row][col] > target` → everything below in this column is larger → `col--`
  - Each step eliminates one row or one column, so at most `m + n` steps
- **Complexity:** Time O(m + n) / Space O(1)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - Rows sorted + columns sorted ≠ the whole matrix is sorted, so a single flat
    binary search does not apply; the staircase exploits the two axes separately
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Search in Rotated Sorted Array II
- **Link:** [LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) | [Solution](../BinarySearch/BinarySearch/SearchInRotatedSortedArrayII.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - Binary search on a rotated array, but duplicates break the "one half is sorted"
    assumption
  - Degenerate case: if `nums[low] == nums[mid] == nums[high]`, neither half can be
    trusted → shrink both ends, which is why the worst case degrades to O(n)
  - Otherwise use the sorted half (`nums[low] <= nums[mid]` → left sorted) and
    check whether `target` falls in its range before deciding direction
- **Complexity:** Time O(log n) average, O(n) worst case / Space O(1)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Find Minimum in Rotated Sorted Array
- **Link:** [LeetCode](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | [Solution](../BinarySearch/BinarySearch/FindMinInRotatedSortedArray.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - Compare `nums[mid]` with `nums[high]`: if `nums[mid] > nums[high]`, the
    rotation point (and thus the minimum) is strictly right of `mid` →
    `low = mid + 1`
  - Otherwise the right half is sorted, so the minimum sits at `mid` or to its
    left → `high = mid`
  - `low < high` means the answer is `nums[low]` on convergence
- **Complexity:** Time O(log n) / Space O(1)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

---

## Day 03 — Friday, 25 Sep 2026

**Topic:** Arrays
**Subtopic:** Two Pointers
**Problems solved:** 2 / 2
**Total time spent:** —

### Summary
Completed 2 Two Pointers problems.

---

### Problem: Merge Sorted Array
- **Link:** [LeetCode](https://leetcode.com/problems/merge-sorted-array/) | [Solution](../Arrays/TwoPointers/MergeSortedArray.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Trapping Rain Water
- **Link:** [LeetCode](https://leetcode.com/problems/trapping-rain-water/) | [Solution](../Arrays/TwoPointers/TrappingRainWater.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

## Day 04 — Saturday, 26 Sep 2026

**Topic:** Arrays + Hashing
**Subtopic:** Divide and Conquer + Hashing and Prefix Sums
**Problems solved:** 4 / 4
**Total time spent:** —

### Summary
Completed Divide and Conquer (Count Inversions via merge-sort, Reverse Pairs) and Hashing (Two Sum, Longest Consecutive Sequence).

---

### Problem: Count Inversions
- **Link:** [GeeksforGeeks](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1) | [Solution](../Arrays/DivideAndConquer/CountInversion.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- fill in -->
- **Complexity:** Time O(n log n) / Space O(n)
- **Mistakes made:**
  - Missing base case and return in countInv; wrong index in left copy; by-value param; int overflow — all fixed
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Reverse Pairs
- **Link:** [LeetCode](https://leetcode.com/problems/reverse-pairs/) | [Solution](../Arrays/DivideAndConquer/ReversePairs.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- Merge-sort counting nums[i] > 2*nums[j] via two-pointer before inplace_merge -->
- **Complexity:** Time O(n log n) / Space O(n)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Two Sum
- **Link:** [LeetCode](https://leetcode.com/problems/two-sum/) | [Solution](../Hashing/HashingAndPrefixSums/TwoSum.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- Hash map: store value -> index, look up target - nums[i] -->
- **Complexity:** Time O(n) / Space O(n)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Longest Consecutive Sequence
- **Link:** [LeetCode](https://leetcode.com/problems/longest-consecutive-sequence/) | [Solution](../Hashing/HashingAndPrefixSums/LongestConsecutiveSequence.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- Insert into unordered_set; count only from sequence starts -->
- **Complexity:** Time O(n) / Space O(n)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

## Day 05 — Sunday, 27 Sep 2026

**Topic:** Hashing
**Subtopic:** Hashing and Prefix Sums
**Problems solved:** 2 / 2
**Total time spent:** —

### Summary
Solved Subarray Sum Equals K and Longest Subarray with Sum K using prefix-sum + frequency/earliest-index maps.

---

### Problem: Subarray Sum Equals K
- **Link:** [LeetCode](https://leetcode.com/problems/subarray-sum-equals-k/) | [Solution](../Hashing/HashingAndPrefixSums/SubarraySumEqualsK.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- Prefix sums; count how many earlier prefix-sum values equal preSum - k -->
- **Complexity:** Time O(n) / Space O(n)
- **Mistakes made:**
  - <!-- fill in -->
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

### Problem: Longest Subarray with Sum K
- **Link:** [GeeksforGeeks](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1) | [Solution](../Hashing/HashingAndPrefixSums/LongestSubarrayWithSumK.cpp)
- **Status:** ☑ Solved
- **Time taken:** —
- **Approach:**
  - <!-- Prefix sums; keep EARLIEST index of each prefix sum so i - preSum[rem] is maximal -->
- **Complexity:** Time O(n) / Space O(n)
- **Mistakes made:**
  - Overwriting preSum with latest index shortened lengths when prefix sums repeated; storing first occurrence fixes it
- **What I learned:**
  - <!-- fill in -->
- **Next steps:**
  - <!-- fill in -->

---

<!--
HOW TO USE THIS LOG:
- Copy the daily block below for each new day and fill it in.
- Update the counters at the top every day.
- Append new days at the bottom, always keeping the most recent day last.

---
## Day 06 — <Day>, <Date>

**Topic:** —
**Subtopic:** —
**Problems solved:** 0
**Total time spent:** —

### Summary

### Problem: _Problem Name_
- **Link:** [LeetCode](https://leetcode.com/problems/) | [Solution](../<Topic>/<Subtopic>/)
- **Status:** ☐ Solved | ☐ Unsolved | ☐ Need Review
- **Time taken:** —
- **Approach:**
  - <!-- What technique/heuristic did you use? -->
- **Complexity:** Time O(?) / Space O(?)
- **Mistakes made:**
  - <!-- Edge cases missed, syntax slips, wrong initial idea... -->
- **What I learned:**
  - <!-- Pattern recognized, takeaway -->
- **Next steps:**
  - <!-- Revisit blindly, try the follow-up, think of a new approach... -->
-->