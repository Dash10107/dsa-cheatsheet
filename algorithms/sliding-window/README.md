# Sliding Window

The sliding window technique is an algorithmic approach for efficiently solving problems that involve a contiguous subarray or substring. The core idea is to maintain a "window" of elements that slides over the data structure, reducing the need for nested loops and often lowering the time complexity from O(n²) to O(n).

### 🤔 How it Works

The technique uses two pointers, often called `start` and `end`, to define the current window. The window slides through the data, and at each step, the algorithm performs calculations on the elements within that window.

There are two main variations:

*   **Fixed-size window:** The window size remains constant throughout the process.
*   **Variable-size window:** The window size can grow or shrink based on certain conditions of the problem.

---

## 🔥 LeetCode Problems

### Fixed-Size Window
- [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) (Easy)
- [Number of Sub-arrays of Size K and Average Greater Than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/) (Medium)
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) (Hard)

### Variable-Size Window
- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) (Medium)
- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) (Hard)
- [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/) (Medium)
- [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) (Medium)
- [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) (Medium)
- [Permutation in String](https://leetcode.com/problems/permutation-in-string/) (Medium)
- [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) (Medium)

💬 **Discussion**: [LeetCode Sliding Window Guide](https://leetcode.com/discuss/general-discussion/657507/)