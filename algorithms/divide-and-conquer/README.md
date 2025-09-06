# Divide and Conquer

Divide and conquer is a fundamental algorithmic paradigm that breaks a problem into smaller subproblems, solves each recursively, and combines their results. It is the basis for many efficient algorithms, especially for sorting, searching, and optimization.

### Key Steps
1. **Divide**: Split the problem into smaller subproblems.
2. **Conquer**: Solve each subproblem recursively.
3. **Combine**: Merge the solutions to subproblems into a final answer.

---

### Advantages
*   **Efficiency:** These algorithms are often very efficient, with time complexities like O(n log n).
*   **Solving Difficult Problems:** It simplifies complex problems by breaking them into smaller, more solvable parts.
*   **Parallelism:** The independent nature of the sub-problems makes this approach well-suited for parallel processing.
*   **Cache Efficiency:** They often have good cache performance.

### Disadvantages
*   **Recursion Overhead:** The recursive nature can lead to high memory usage due to stack overhead.
*   **Implementation Complexity:** Can be more complex to implement than iterative solutions.
*   **Not Always Suitable:** Not ideal for problems that cannot be easily divided into independent sub-problems.

---

## Common Use Cases
- Sorting (Merge Sort, Quick Sort)
- Maximum Subarray Sum
- Closest Pair of Points
- Counting Inversions
- Karatsuba Multiplication
- Fast Fourier Transform (FFT)
- Matrix Multiplication (Strassen's)

---

## 🔥 LeetCode Problems

### Easy
- [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
- [Majority Element](https://leetcode.com/problems/majority-element/)

### Medium
- [Sort an Array (Merge Sort)](https://leetcode.com/problems/sort-an-array/)
- [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
- [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/)
- [Longest Nice Substring](https://leetcode.com/problems/longest-nice-substring/)

### Hard
- [Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)
- [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
- [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/)
- [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
- [The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/)

---

## Tips
- Recursion is at the heart of divide and conquer.
- Base cases are crucial for correctness.
- Combining step can often be the trickiest part (e.g., merging in merge sort).
- Many problems can be optimized by switching to iterative or hybrid approaches for small subproblems.

---

## References
- [Divide and Conquer - LeetCode Guide](https://leetcode.com/discuss/general-discussion/1127238/)
- [Wikipedia: Divide and Conquer](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm)