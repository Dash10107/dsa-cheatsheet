"""
Arrays Data Structure Implementation
===================================

This file contains common array operations and implementations.
"""

class DynamicArray:
    """
    Dynamic array implementation with automatic resizing.
    """
    
    def __init__(self, capacity=2):
        self.capacity = capacity
        self.size = 0
        self.data = [None] * capacity
    
    def __len__(self):
        return self.size
    
    def __getitem__(self, index):
        if 0 <= index < self.size:
            return self.data[index]
        raise IndexError("Index out of range")
    
    def __setitem__(self, index, value):
        if 0 <= index < self.size:
            self.data[index] = value
        else:
            raise IndexError("Index out of range")
    
    def append(self, value):
        """Add element to end of array."""
        if self.size >= self.capacity:
            self._resize()
        
        self.data[self.size] = value
        self.size += 1
    
    def insert(self, index, value):
        """Insert element at given index."""
        if index < 0 or index > self.size:
            raise IndexError("Index out of range")
        
        if self.size >= self.capacity:
            self._resize()
        
        # Shift elements to the right
        for i in range(self.size, index, -1):
            self.data[i] = self.data[i - 1]
        
        self.data[index] = value
        self.size += 1
    
    def delete(self, index):
        """Delete element at given index."""
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range")
        
        # Shift elements to the left
        for i in range(index, self.size - 1):
            self.data[i] = self.data[i + 1]
        
        self.size -= 1
    
    def _resize(self):
        """Double the capacity of the array."""
        self.capacity *= 2
        new_data = [None] * self.capacity
        
        for i in range(self.size):
            new_data[i] = self.data[i]
        
        self.data = new_data
    
    def __str__(self):
        return str(self.data[:self.size])


def reverse_array(arr):
    """
    Reverse array in-place.
    
    Args:
        arr: Array to reverse
    
    Returns:
        None (modifies array in-place)
    """
    left, right = 0, len(arr) - 1
    
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1


def rotate_array(arr, k):
    """
    Rotate array to the right by k positions.
    
    Args:
        arr: Array to rotate
        k: Number of positions to rotate
    
    Returns:
        None (modifies array in-place)
    """
    n = len(arr)
    k = k % n  # Handle k > n
    
    # Reverse entire array
    reverse_array(arr)
    
    # Reverse first k elements
    reverse_array(arr[:k])
    
    # Reverse remaining elements
    reverse_array(arr[k:])


def find_peak_element(arr):
    """
    Find a peak element in array (greater than neighbors).
    
    Args:
        arr: Array of integers
    
    Returns:
        Index of a peak element
    """
    left, right = 0, len(arr) - 1
    
    while left < right:
        mid = left + (right - left) // 2
        
        if arr[mid] > arr[mid + 1]:
            right = mid
        else:
            left = mid + 1
    
    return left


def product_except_self(nums):
    """
    Product of array except self without division.
    
    Args:
        nums: Array of integers
    
    Returns:
        Array where result[i] is product of all elements except nums[i]
    """
    n = len(nums)
    result = [1] * n
    
    # Calculate prefix products
    for i in range(1, n):
        result[i] = result[i - 1] * nums[i - 1]
    
    # Calculate suffix products and multiply
    suffix_product = 1
    for i in range(n - 1, -1, -1):
        result[i] *= suffix_product
        suffix_product *= nums[i]
    
    return result


def spiral_matrix(matrix):
    """
    Return elements of matrix in spiral order.
    
    Args:
        matrix: 2D matrix
    
    Returns:
        List of elements in spiral order
    """
    if not matrix or not matrix[0]:
        return []
    
    result = []
    top, bottom = 0, len(matrix) - 1
    left, right = 0, len(matrix[0]) - 1
    
    while top <= bottom and left <= right:
        # Traverse right
        for j in range(left, right + 1):
            result.append(matrix[top][j])
        top += 1
        
        # Traverse down
        for i in range(top, bottom + 1):
            result.append(matrix[i][right])
        right -= 1
        
        # Traverse left
        if top <= bottom:
            for j in range(right, left - 1, -1):
                result.append(matrix[bottom][j])
            bottom -= 1
        
        # Traverse up
        if left <= right:
            for i in range(bottom, top - 1, -1):
                result.append(matrix[i][left])
            left += 1
    
    return result


def merge_intervals(intervals):
    """
    Merge overlapping intervals.
    
    Args:
        intervals: List of [start, end] intervals
    
    Returns:
        List of merged intervals
    """
    if not intervals:
        return []
    
    intervals.sort(key=lambda x: x[0])
    merged = [intervals[0]]
    
    for current in intervals[1:]:
        last = merged[-1]
        
        if current[0] <= last[1]:
            # Overlapping intervals, merge them
            last[1] = max(last[1], current[1])
        else:
            # Non-overlapping, add to result
            merged.append(current)
    
    return merged


def find_duplicate(nums):
    """
    Find duplicate number using Floyd's cycle detection.
    
    Args:
        nums: Array with one duplicate number
    
    Returns:
        Duplicate number
    """
    # Phase 1: Find intersection point
    slow = fast = nums[0]
    
    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast:
            break
    
    # Phase 2: Find entrance to cycle
    slow = nums[0]
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]
    
    return slow


def max_subarray_sum(nums):
    """
    Maximum sum of contiguous subarray (Kadane's algorithm).
    
    Args:
        nums: Array of integers
    
    Returns:
        Maximum subarray sum
    """
    max_so_far = max_ending_here = nums[0]
    
    for i in range(1, len(nums)):
        max_ending_here = max(nums[i], max_ending_here + nums[i])
        max_so_far = max(max_so_far, max_ending_here)
    
    return max_so_far


def two_sum(nums, target):
    """
    Find two numbers that sum to target.
    
    Args:
        nums: Array of integers
        target: Target sum
    
    Returns:
        Indices of two numbers that sum to target
    """
    num_map = {}
    
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_map:
            return [num_map[complement], i]
        num_map[num] = i
    
    return []


def three_sum(nums):
    """
    Find all unique triplets that sum to zero.
    
    Args:
        nums: Array of integers
    
    Returns:
        List of unique triplets
    """
    nums.sort()
    result = []
    
    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        left, right = i + 1, len(nums) - 1
        
        while left < right:
            current_sum = nums[i] + nums[left] + nums[right]
            
            if current_sum == 0:
                result.append([nums[i], nums[left], nums[right]])
                
                # Skip duplicates
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                
                left += 1
                right -= 1
            elif current_sum < 0:
                left += 1
            else:
                right -= 1
    
    return result


# Test cases
if __name__ == "__main__":
    # Test DynamicArray
    arr = DynamicArray()
    arr.append(1)
    arr.append(2)
    arr.append(3)
    print(f"Dynamic array: {arr}")
    print(f"Length: {len(arr)}")
    print(f"Element at index 1: {arr[1]}")
    
    # Test reverse array
    nums = [1, 2, 3, 4, 5]
    reverse_array(nums)
    print(f"Reversed array: {nums}")
    
    # Test rotate array
    nums = [1, 2, 3, 4, 5, 6, 7]
    rotate_array(nums, 3)
    print(f"Rotated array: {nums}")
    
    # Test find peak element
    nums = [1, 2, 3, 1]
    print(f"Peak element index: {find_peak_element(nums)}")
    
    # Test product except self
    nums = [1, 2, 3, 4]
    print(f"Product except self: {product_except_self(nums)}")
    
    # Test spiral matrix
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    print(f"Spiral order: {spiral_matrix(matrix)}")
    
    # Test merge intervals
    intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
    print(f"Merged intervals: {merge_intervals(intervals)}")
    
    # Test find duplicate
    nums = [1, 3, 4, 2, 2]
    print(f"Duplicate number: {find_duplicate(nums)}")
    
    # Test max subarray sum
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(f"Maximum subarray sum: {max_subarray_sum(nums)}")
    
    # Test two sum
    nums = [2, 7, 11, 15]
    target = 9
    print(f"Two sum indices: {two_sum(nums, target)}")
    
    # Test three sum
    nums = [-1, 0, 1, 2, -1, -4]
    print(f"Three sum triplets: {three_sum(nums)}")
