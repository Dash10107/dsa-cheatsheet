# Two Pointers

The two-pointers technique is a common algorithmic pattern that uses two pointers (variables that store indices or references) to traverse a data structure, typically an array, list, or string. By moving these pointers based on certain conditions, you can often solve problems more efficiently, commonly reducing the time complexity from O(n²) to O(n) and using O(1) space.

### 🤔 How It Works

There are two main approaches to the two-pointers technique:

#### 1. Opposite Ends
In this strategy, one pointer starts at the beginning of the data structure, and the other starts at the end. They move towards each other until they meet or cross. This is ideal for problems on **sorted arrays** where you need to find a pair of elements that satisfy a certain condition.

#### 2. Same Direction (Slow and Fast Pointers)
In this approach, both pointers start at or near the same position but move in the same direction at different speeds. This is also known as the "sliding window" or "tortoise and hare" algorithm. This pattern is useful for detecting cycles, finding the middle of a linked list, or solving problems that involve a "window" or subarray of elements.

---

## 🔥 LeetCode Problems

### Opposite Ends
- [Two Sum II - Input Array is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) (Easy)
- [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) (Easy)
- [3Sum](https://leetcode.com/problems/3sum/) (Medium)
- [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) (Medium)
- [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) (Hard)

### Same Direction (Slow and Fast Pointers)
- [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) (Medium)
- [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) (Easy)
- [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) (Easy)
- [Move Zeroes](https://leetcode.com/problems/move-zeroes/) (Easy)
- [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) (Easy)
- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) (Hard)

💬 **Discussion**: [LeetCode Two Pointers Guide](https://leetcode.com/discuss/general-discussion/657507/)