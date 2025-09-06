"""
Binary Search Pattern Template
=============================

This template provides common binary search implementations for various problem types.
"""

def binary_search(arr, target):
    """
    Standard binary search template.
    
    Args:
        arr: Sorted array
        target: Target value to search for
    
    Returns:
        Index of target if found, -1 otherwise
    """
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1


def find_first_occurrence(arr, target):
    """
    Find first occurrence of target in sorted array.
    
    Args:
        arr: Sorted array
        target: Target value
    
    Returns:
        Index of first occurrence, -1 if not found
    """
    left, right = 0, len(arr) - 1
    result = -1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            result = mid
            right = mid - 1  # Continue searching left
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return result


def find_last_occurrence(arr, target):
    """
    Find last occurrence of target in sorted array.
    
    Args:
        arr: Sorted array
        target: Target value
    
    Returns:
        Index of last occurrence, -1 if not found
    """
    left, right = 0, len(arr) - 1
    result = -1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            result = mid
            left = mid + 1  # Continue searching right
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return result


def search_insert_position(arr, target):
    """
    Find insertion position for target in sorted array.
    
    Args:
        arr: Sorted array
        target: Target value
    
    Returns:
        Index where target should be inserted
    """
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return left


def search_rotated_array(arr, target):
    """
    Search in rotated sorted array.
    
    Args:
        arr: Rotated sorted array
        target: Target value
    
    Returns:
        Index of target if found, -1 otherwise
    """
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            return mid
        
        # Check which half is sorted
        if arr[left] <= arr[mid]:  # Left half is sorted
            if arr[left] <= target < arr[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:  # Right half is sorted
            if arr[mid] < target <= arr[right]:
                left = mid + 1
            else:
                right = mid - 1
    
    return -1


def find_minimum_rotated(arr):
    """
    Find minimum element in rotated sorted array.
    
    Args:
        arr: Rotated sorted array
    
    Returns:
        Minimum element
    """
    left, right = 0, len(arr) - 1
    
    while left < right:
        mid = left + (right - left) // 2
        
        if arr[mid] > arr[right]:
            left = mid + 1
        else:
            right = mid
    
    return arr[left]


def find_peak_element(arr):
    """
    Find peak element in array.
    
    Args:
        arr: Array of integers
    
    Returns:
        Index of any peak element
    """
    left, right = 0, len(arr) - 1
    
    while left < right:
        mid = left + (right - left) // 2
        
        if arr[mid] > arr[mid + 1]:
            right = mid
        else:
            left = mid + 1
    
    return left


def search_2d_matrix(matrix, target):
    """
    Search in 2D matrix where each row and column is sorted.
    
    Args:
        matrix: 2D sorted matrix
        target: Target value
    
    Returns:
        True if target is found, False otherwise
    """
    if not matrix or not matrix[0]:
        return False
    
    rows, cols = len(matrix), len(matrix[0])
    left, right = 0, rows * cols - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        mid_value = matrix[mid // cols][mid % cols]
        
        if mid_value == target:
            return True
        elif mid_value < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return False


def sqrt_binary_search(x):
    """
    Find square root using binary search.
    
    Args:
        x: Non-negative integer
    
    Returns:
        Integer square root
    """
    if x < 2:
        return x
    
    left, right = 2, x // 2
    
    while left <= right:
        mid = left + (right - left) // 2
        square = mid * mid
        
        if square == x:
            return mid
        elif square < x:
            left = mid + 1
        else:
            right = mid - 1
    
    return right


# Test cases
if __name__ == "__main__":
    # Test standard binary search
    arr = [1, 3, 5, 7, 9, 11, 13]
    target = 7
    print(f"Binary search for {target}: {binary_search(arr, target)}")
    
    # Test first occurrence
    arr = [1, 2, 2, 2, 3, 4, 5]
    target = 2
    print(f"First occurrence of {target}: {find_first_occurrence(arr, target)}")
    
    # Test last occurrence
    print(f"Last occurrence of {target}: {find_last_occurrence(arr, target)}")
    
    # Test search insert position
    arr = [1, 3, 5, 6]
    target = 4
    print(f"Insert position for {target}: {search_insert_position(arr, target)}")
    
    # Test rotated array search
    arr = [4, 5, 6, 7, 0, 1, 2]
    target = 0
    print(f"Search in rotated array for {target}: {search_rotated_array(arr, target)}")
    
    # Test find minimum in rotated array
    print(f"Minimum in rotated array: {find_minimum_rotated(arr)}")
    
    # Test find peak element
    arr = [1, 2, 3, 1]
    print(f"Peak element index: {find_peak_element(arr)}")
    
    # Test 2D matrix search
    matrix = [
        [1, 4, 7, 11],
        [2, 5, 8, 12],
        [3, 6, 9, 16]
    ]
    target = 5
    print(f"Search in 2D matrix for {target}: {search_2d_matrix(matrix, target)}")
    
    # Test square root
    x = 8
    print(f"Square root of {x}: {sqrt_binary_search(x)}")
