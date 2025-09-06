"""
Divide and Conquer Pattern Template
==================================

This template provides common divide and conquer implementations for various problem types.
"""

def merge_sort(arr):
    """Sort an array using merge sort (divide and conquer)."""
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

def quick_sort(arr):
    """Sort an array using quick sort (divide and conquer)."""
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def max_subarray_sum(arr):
    """Find the maximum subarray sum using divide and conquer (Kadane's alternative)."""
    def helper(l, r):
        if l == r:
            return arr[l], arr[l], arr[l], arr[l]
        m = (l + r) // 2
        l_sum, l_max, l_prefix, l_suffix = helper(l, m)
        r_sum, r_max, r_prefix, r_suffix = helper(m + 1, r)
        total = l_sum + r_sum
        max_sum = max(l_max, r_max, l_suffix + r_prefix)
        prefix = max(l_prefix, l_sum + r_prefix)
        suffix = max(r_suffix, r_sum + l_suffix)
        return total, max_sum, prefix, suffix
    if not arr:
        return 0
    return helper(0, len(arr) - 1)[1]

# Test cases
if __name__ == "__main__":
    arr = [3, 5, 1, 6, 2, 7, 4]
    print(f"Merge sort: {merge_sort(arr)}")
    print(f"Quick sort: {quick_sort(arr)}")
    arr2 = [-2,1,-3,4,-1,2,1,-5,4]
    print(f"Max subarray sum: {max_subarray_sum(arr2)}")
