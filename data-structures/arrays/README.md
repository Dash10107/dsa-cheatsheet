# Arrays Data Structure

Arrays are a fundamental data structure that stores elements of the same type in contiguous memory locations, allowing for efficient random access.

## 🎯 Key Characteristics

- **Fixed Size**: Size is determined at creation
- **Homogeneous**: All elements must be of the same type
- **Random Access**: O(1) access time by index
- **Contiguous Memory**: Elements stored in adjacent memory locations

## 📊 Time & Space Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Access | O(1) | O(1) |
| Search | O(n) | O(1) |
| Insertion | O(n) | O(1) |
| Deletion | O(n) | O(1) |
| Resize | O(n) | O(n) |

## 🔧 Common Operations

### Basic Operations
- **Access**: `arr[index]`
- **Update**: `arr[index] = value`
- **Length**: `len(arr)`

### Array Manipulation
- **Reverse**: Reverse elements in-place
- **Rotate**: Rotate array by k positions
- **Sort**: Sort array elements
- **Search**: Find element or position

### Advanced Operations
- **Two Pointers**: Process array with two indices
- **Sliding Window**: Process subarrays efficiently
- **Prefix Sum**: Precompute sums for range queries

## 🎯 Common Problems


### LeetCode Problems

- [Two Sum](https://leetcode.com/problems/two-sum/)
- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
- [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
- [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
- [Rotate Array](https://leetcode.com/problems/rotate-array/)
- [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)
- [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)
- [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)
- [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
- [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)
- [Move Zeroes](https://leetcode.com/problems/move-zeroes/)
- [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

## 💡 Key Insights

- Use indices for random access
- Consider space-time tradeoffs
- Leverage sorting for optimization
- Use two pointers for efficiency
- Consider in-place operations

## 🚀 Practice Tips

1. Master basic operations first
2. Practice with different array sizes
3. Learn common patterns (two pointers, sliding window)
4. Understand when to sort vs. when not to
5. Practice in-place modifications
