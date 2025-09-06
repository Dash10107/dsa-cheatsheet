# Monotonic Queue

A monotonic queue is a data structure that maintains its elements in a strictly increasing or decreasing order. It is typically implemented using a double-ended queue (deque), which allows for efficient addition and removal of elements from both the front and back.

### 🤔 How It Works

The core principle involves a conditional push operation:

*   **Enqueue (Push)**: Before adding a new element to the back of the queue, the queue is "cleaned." For an increasing queue, all elements from the back that are greater than the new element are removed. For a decreasing queue, all elements from the back that are less than the new element are removed.
*   **Dequeue (Pop)**: Elements are typically removed from the front, often to discard elements that are no longer within the current problem scope (like a sliding window).

This process ensures that the element at the front of the queue is always the minimum (for an increasing queue) or maximum (for a decreasing queue) within the current set of elements in the queue.

### ⏱ Complexity
- Time: O(N) - each element is pushed and popped at most once.
- Space: O(K) - where K is the window size or number of elements in the queue.

---

### 📖 Common Applications
*   **Sliding Window Maximum/Minimum**: The classic application.
*   **Next Greater/Smaller Element**: Finding the next element in a sequence that is greater or smaller than the current one.
*   **Dynamic Programming Optimization**.

---

## 🔥 LeetCode Problems

### Medium
- [Max Consecutive Ones II](https://leetcode.com/problems/max-consecutive-ones-ii/)

### Hard
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
- [Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)
- [Constrained Subsequence Sum](https://leetcode.com/problems/constrained-subsequence-sum/)
- [Jump Game VI](https://leetcode.com/problems/jump-game-vi/)
- [Delivering Boxes from Storage to Ports](https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/)

💬 **Discussion**: [LeetCode Monotonic Queue Guide](https://leetcode.com/discuss/general-discussion/657507/)