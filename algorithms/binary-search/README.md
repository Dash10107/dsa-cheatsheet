# Binary Search

Binary search is a highly efficient algorithm for finding a specific value within a **sorted** array. Its strategy is to repeatedly divide the search interval in half. This "divide and conquer" approach makes it significantly faster than checking every single element one by one (linear search).

### 🤔 How It Works

The core idea is to compare the target value with the middle element of the array.

1.  **Find the middle element:** The algorithm first looks at the element in the exact middle of the array.
2.  **Compare:**
    *   If the middle element is the **target value**, the search is complete.
    *   If the target value is **less than** the middle element, the algorithm knows the target must be in the lower (left) half of the array.
    *   If the target value is **greater than** the middle element, the search continues in the upper (right) half.
3.  **Repeat:** The process of dividing the relevant half of the array and comparing it with the middle element is repeated until the value is found or the search interval becomes empty, which means the target is not in the array.

### ⚠️ Prerequisite

The single most important condition for binary search is that the data collection **must be sorted**.

### 📖 When to Use
For searching in sorted arrays or finding boundaries in monotonic functions.

### ⏱ Complexity
- Time: O(log N). This means that even if you double the number of elements in the array, it only takes one extra step to find the target.
- Space: O(1) for the iterative version.

---

## 🔥 LeetCode Problems

### Easy
- [Binary Search](https://leetcode.com/problems/binary-search/)
- [Sqrt(x)](https://leetcode.com/problems/sqrtx/)
- [Search Insert Position](https://leetcode.com/problems/search-insert-position/)
- [First Bad Version](https://leetcode.com/problems/first-bad-version/)

### Medium
- [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
- [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- [Find Peak Element](https://leetcode.com/problems/find-peak-element/)

### Hard
- [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)
- [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)
- [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)

💬 **Discussion**: [LeetCode Binary Search Guide](https://leetcode.com/discuss/general-discussion/657507/)