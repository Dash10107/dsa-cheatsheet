"""
Prefix Sum Pattern Template
==========================

This template provides common prefix sum implementations for various problem types.
"""

def build_prefix_sum_1d(arr):
    """
    Build 1D prefix sum array.
    
    Args:
        arr: Input array
    
    Returns:
        Prefix sum array (1-indexed)
    """
    prefix = [0] * (len(arr) + 1)
    for i in range(len(arr)):
        prefix[i + 1] = prefix[i] + arr[i]
    return prefix


def range_sum_1d(prefix, left, right):
    """
    Get sum of range [left, right] using prefix sum.
    
    Args:
        prefix: Prefix sum array
        left: Start index (inclusive)
        right: End index (inclusive)
    
    Returns:
        Sum of elements in range
    """
    return prefix[right + 1] - prefix[left]


def build_prefix_sum_2d(matrix):
    """
    Build 2D prefix sum matrix.
    
    Args:
        matrix: 2D input matrix
    
    Returns:
        2D prefix sum matrix (1-indexed)
    """
    rows, cols = len(matrix), len(matrix[0])
    prefix = [[0] * (cols + 1) for _ in range(rows + 1)]
    
    for i in range(rows):
        for j in range(cols):
            prefix[i + 1][j + 1] = (prefix[i][j + 1] + 
                                   prefix[i + 1][j] - 
                                   prefix[i][j] + 
                                   matrix[i][j])
    return prefix


def range_sum_2d(prefix, row1, col1, row2, col2):
    """
    Get sum of rectangle using 2D prefix sum.
    
    Args:
        prefix: 2D prefix sum matrix
        row1, col1: Top-left corner (inclusive)
        row2, col2: Bottom-right corner (inclusive)
    
    Returns:
        Sum of elements in rectangle
    """
    return (prefix[row2 + 1][col2 + 1] - 
            prefix[row1][col2 + 1] - 
            prefix[row2 + 1][col1] + 
            prefix[row1][col1])


def subarray_sum_equals_k(nums, k):
    """
    Find number of subarrays with sum equal to k.
    
    Args:
        nums: Array of integers
        k: Target sum
    
    Returns:
        Number of subarrays with sum k
    """
    count = 0
    prefix_sum = 0
    sum_count = {0: 1}  # prefix_sum -> count
    
    for num in nums:
        prefix_sum += num
        
        # If (prefix_sum - k) exists, we found a subarray
        if prefix_sum - k in sum_count:
            count += sum_count[prefix_sum - k]
        
        # Update count for current prefix sum
        sum_count[prefix_sum] = sum_count.get(prefix_sum, 0) + 1
    
    return count


def find_pivot_index(nums):
    """
    Find pivot index where left sum equals right sum.
    
    Args:
        nums: Array of integers
    
    Returns:
        Pivot index, -1 if not found
    """
    total_sum = sum(nums)
    left_sum = 0
    
    for i, num in enumerate(nums):
        if left_sum == total_sum - left_sum - num:
            return i
        left_sum += num
    
    return -1


def product_except_self(nums):
    """
    Product of array except self using prefix and suffix products.
    
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


def continuous_subarray_sum(nums, k):
    """
    Check if array has continuous subarray with sum multiple of k.
    
    Args:
        nums: Array of integers
        k: Target multiple
    
    Returns:
        True if such subarray exists, False otherwise
    """
    if k == 0:
        # Check for consecutive zeros
        for i in range(len(nums) - 1):
            if nums[i] == 0 and nums[i + 1] == 0:
                return True
        return False
    
    remainder_map = {0: -1}  # remainder -> first occurrence index
    prefix_sum = 0
    
    for i, num in enumerate(nums):
        prefix_sum += num
        remainder = prefix_sum % k
        
        if remainder in remainder_map:
            if i - remainder_map[remainder] > 1:
                return True
        else:
            remainder_map[remainder] = i
    
    return False


def max_subarray_sum_circular(nums):
    """
    Find maximum sum of circular subarray.
    
    Args:
        nums: Array of integers
    
    Returns:
        Maximum sum of circular subarray
    """
    # Case 1: Maximum subarray is not circular
    max_so_far = max_ending_here = nums[0]
    for i in range(1, len(nums)):
        max_ending_here = max(nums[i], max_ending_here + nums[i])
        max_so_far = max(max_so_far, max_ending_here)
    
    # Case 2: Maximum subarray is circular
    min_so_far = min_ending_here = nums[0]
    total_sum = nums[0]
    
    for i in range(1, len(nums)):
        total_sum += nums[i]
        min_ending_here = min(nums[i], min_ending_here + nums[i])
        min_so_far = min(min_so_far, min_ending_here)
    
    # If all elements are negative, return max_so_far
    if total_sum == min_so_far:
        return max_so_far
    
    return max(max_so_far, total_sum - min_so_far)


# Test cases
if __name__ == "__main__":
    # Test 1D prefix sum
    arr = [1, 2, 3, 4, 5]
    prefix = build_prefix_sum_1d(arr)
    print(f"Prefix sum: {prefix}")
    print(f"Range sum [1, 3]: {range_sum_1d(prefix, 1, 3)}")
    
    # Test 2D prefix sum
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    prefix_2d = build_prefix_sum_2d(matrix)
    print(f"2D Range sum [0,0] to [1,1]: {range_sum_2d(prefix_2d, 0, 0, 1, 1)}")
    
    # Test subarray sum equals k
    nums = [1, 1, 1]
    k = 2
    print(f"Subarrays with sum {k}: {subarray_sum_equals_k(nums, k)}")
    
    # Test find pivot index
    nums = [1, 7, 3, 6, 5, 6]
    print(f"Pivot index: {find_pivot_index(nums)}")
    
    # Test product except self
    nums = [1, 2, 3, 4]
    print(f"Product except self: {product_except_self(nums)}")
    
    # Test continuous subarray sum
    nums = [23, 2, 4, 6, 7]
    k = 6
    print(f"Continuous subarray sum multiple of {k}: {continuous_subarray_sum(nums, k)}")
    
    # Test max circular subarray sum
    nums = [5, -3, 5]
    print(f"Max circular subarray sum: {max_subarray_sum_circular(nums)}")
