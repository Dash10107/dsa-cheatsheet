# Monotonic Stack

A monotonic stack is a stack data structure where the elements are always in a specific order, either consistently increasing or decreasing. This property makes it a powerful tool for solving certain types of problems more efficiently than with a standard stack.

### 🤔 How It Works

The core principle of a monotonic stack is to maintain its ordered property during push operations. When a new element arrives, it's compared to the element at the top of the stack. If adding the new element would violate the monotonic property (e.g., pushing a smaller element onto an increasing stack), elements are popped from the stack until the property is no longer violated. After this, the new element can be pushed.

This process ensures that for many problems, each element is pushed and popped at most once, leading to an efficient overall time complexity of O(n).

### ⏱ Complexity
- Time: O(N) - each element is pushed and popped at most once.
- Space: O(N) - in the worst case, all elements are pushed onto the stack.

---

### 📖 Common Applications
*   **Next Greater/Smaller Element:** For each element in an array, find the first element to its right/left that is larger/smaller.
*   **Largest Rectangle in Histogram:** Finding the area of the largest rectangle that can be formed within a histogram.
*   **Trapping Rain Water:** Calculating the amount of water that can be trapped between bars of varying heights.

---

## 🔥 LeetCode Problems

### Medium
- [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)
- [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)
- [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)
- [Remove K Digits](https://leetcode.com/problems/remove-k-digits/)
- [Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/)
- [Maximum Width Ramp](https://leetcode.com/problems/maximum-width-ramp/)

### Hard
- [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
- [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
- [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)
- [Number of Visible People in a Queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue/)

💬 **Discussion**: [LeetCode Monotonic Stack Guide](https://leetcode.com/discuss/general-discussion/657507/)