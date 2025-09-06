# Prefix Sum

A prefix sum is a technique used in computer science to efficiently calculate the sum of elements within a range or subarray. It involves creating a new array, often called a prefix sum array or cumulative sum array, where each element is the sum of all elements up to that index in the original array.

### 🤔 How it Works

Given an input array, `A`, the prefix sum array, `P`, is constructed as follows:
*   `P[0] = A[0]`
*   `P[1] = A[0] + A[1]`
*   `P[2] = A[0] + A[1] + A[2]`
*   ...and so on.

The general formula is: `P[i] = P[i-1] + A[i]`.

The main advantage of using a prefix sum array is that it allows you to find the sum of any subarray (a range of elements) in constant time, O(1).

To find the sum of elements from index `L` to `R` (inclusive), you can use the precomputed prefix sum array with the following formula:

`Sum(L, R) = P[R] - P[L-1]`

---

### 📖 Applications
*   **Range Sum Queries:** The most direct application.
*   **Subarray Problems:** Finding subarrays with specific properties.
*   **2D Prefix Sums:** Extending the concept to 2D to calculate the sum of a submatrix.
*   **Dynamic Programming:** Can simplify calculations in some DP problems.

---

## 🔥 LeetCode Problems

### Easy
- [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)
- [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)
- [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)

### Medium
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
- [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/)
- [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

### Hard
- [Maximum Sum of 3 Non-Overlapping Subarrays](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/)
- [Maximum Subarray Sum with One Deletion](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/)
- [Path Sum III](https://leetcode.com/problems/path-sum-iii/)

💬 **Discussion**: [LeetCode Prefix Sum Guide](https://leetcode.com/discuss/general-discussion/657507/)