"""
Array Utilities
===============

This module provides common array manipulation functions for DSA and competitive programming.
"""

def rotate_left(arr, k):
    """Rotate array left by k positions."""
    n = len(arr)
    k = k % n
    return arr[k:] + arr[:k]

def rotate_right(arr, k):
    """Rotate array right by k positions."""
    n = len(arr)
    k = k % n
    return arr[-k:] + arr[:-k]

def reverse(arr):
    """Return a reversed copy of the array."""
    return arr[::-1]

def prefix_min(arr):
    """Return prefix minimums of the array."""
    result = []
    current = float('inf')
    for x in arr:
        current = min(current, x)
        result.append(current)
    return result

def prefix_max(arr):
    """Return prefix maximums of the array."""
    result = []
    current = float('-inf')
    for x in arr:
        current = max(current, x)
        result.append(current)
    return result

def suffix_min(arr):
    """Return suffix minimums of the array."""
    n = len(arr)
    result = [0] * n
    current = int(1e18)  # Use a large int instead of float('inf')
    for i in range(n - 1, -1, -1):
        current = min(current, arr[i])
        result[i] = int(current)
    return result

def suffix_max(arr):
    """Return suffix maximums of the array."""
    n = len(arr)
    result = [0] * n
    current = int(-1e18)  # Use a small int instead of float('-inf')
    for i in range(n - 1, -1, -1):
        current = max(current, arr[i])
        result[i] = int(current)
    return result

def is_sorted(arr):
    """Check if the array is sorted in non-decreasing order."""
    return all(arr[i] <= arr[i+1] for i in range(len(arr)-1))

# Test cases
if __name__ == "__main__":
    arr = [1, 3, 2, 5, 4]
    print(f"Rotate left by 2: {rotate_left(arr, 2)}")
    print(f"Rotate right by 2: {rotate_right(arr, 2)}")
    print(f"Reverse: {reverse(arr)}")
    print(f"Prefix min: {prefix_min(arr)}")
    print(f"Prefix max: {prefix_max(arr)}")
    print(f"Suffix min: {suffix_min(arr)}")
    print(f"Suffix max: {suffix_max(arr)}")
    print(f"Is sorted? {is_sorted(arr)}")
