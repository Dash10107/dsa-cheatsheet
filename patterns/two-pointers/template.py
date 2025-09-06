"""
Two Pointers Pattern Template
============================

This template provides common two pointers implementations for various problem types.
"""

def two_sum_sorted(arr, target):
    """
    Template for finding two numbers that sum to target in sorted array.
    
    Args:
        arr: Sorted array of integers
        target: Target sum
    
    Returns:
        Indices of the two numbers that sum to target
    """
    left, right = 0, len(arr) - 1
    
    while left < right:
        current_sum = arr[left] + arr[right]
        
        if current_sum == target:
            return [left, right]
        elif current_sum < target:
            left += 1
        else:
            right -= 1
    
    return [-1, -1]


def three_sum(arr, target):
    """
    Template for finding three numbers that sum to target.
    
    Args:
        arr: Array of integers
        target: Target sum
    
    Returns:
        List of triplets that sum to target
    """
    arr.sort()
    result = []
    
    for i in range(len(arr) - 2):
        # Skip duplicates for first number
        if i > 0 and arr[i] == arr[i-1]:
            continue
        
        left, right = i + 1, len(arr) - 1
        
        while left < right:
            current_sum = arr[i] + arr[left] + arr[right]
            
            if current_sum == target:
                result.append([arr[i], arr[left], arr[right]])
                
                # Skip duplicates
                while left < right and arr[left] == arr[left + 1]:
                    left += 1
                while left < right and arr[right] == arr[right - 1]:
                    right -= 1
                
                left += 1
                right -= 1
            elif current_sum < target:
                left += 1
            else:
                right -= 1
    
    return result


def remove_duplicates(arr):
    """
    Template for removing duplicates from sorted array.
    
    Args:
        arr: Sorted array
    
    Returns:
        New length of array after removing duplicates
    """
    if not arr:
        return 0
    
    slow = 0
    
    for fast in range(1, len(arr)):
        if arr[fast] != arr[slow]:
            slow += 1
            arr[slow] = arr[fast]
    
    return slow + 1


def valid_palindrome(s):
    """
    Template for checking if string is palindrome.
    
    Args:
        s: Input string
    
    Returns:
        True if string is palindrome, False otherwise
    """
    left, right = 0, len(s) - 1
    
    while left < right:
        # Skip non-alphanumeric characters
        while left < right and not s[left].isalnum():
            left += 1
        while left < right and not s[right].isalnum():
            right -= 1
        
        # Compare characters (case insensitive)
        if s[left].lower() != s[right].lower():
            return False
        
        left += 1
        right -= 1
    
    return True


def container_with_most_water(height):
    """
    Template for container with most water problem.
    
    Args:
        height: Array of heights
    
    Returns:
        Maximum area of water that can be contained
    """
    left, right = 0, len(height) - 1
    max_area = 0
    
    while left < right:
        # Calculate current area
        width = right - left
        current_height = min(height[left], height[right])
        current_area = width * current_height
        max_area = max(max_area, current_area)
        
        # Move pointer with smaller height
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    
    return max_area


def trapping_rain_water(height):
    """
    Template for trapping rain water problem.
    
    Args:
        height: Array of heights
    
    Returns:
        Amount of water that can be trapped
    """
    if not height:
        return 0
    
    left, right = 0, len(height) - 1
    left_max, right_max = 0, 0
    water = 0
    
    while left < right:
        if height[left] < height[right]:
            if height[left] >= left_max:
                left_max = height[left]
            else:
                water += left_max - height[left]
            left += 1
        else:
            if height[right] >= right_max:
                right_max = height[right]
            else:
                water += right_max - height[right]
            right -= 1
    
    return water


def sort_colors(nums):
    """
    Template for Dutch National Flag problem (sort colors).
    
    Args:
        nums: Array containing only 0s, 1s, and 2s
    
    Returns:
        None (sorts in place)
    """
    low, mid, high = 0, 0, len(nums) - 1
    
    while mid <= high:
        if nums[mid] == 0:
            nums[low], nums[mid] = nums[mid], nums[low]
            low += 1
            mid += 1
        elif nums[mid] == 1:
            mid += 1
        else:  # nums[mid] == 2
            nums[mid], nums[high] = nums[high], nums[mid]
            high -= 1


# Test cases
if __name__ == "__main__":
    # Test two sum sorted
    arr = [2, 7, 11, 15]
    target = 9
    print(f"Two sum indices: {two_sum_sorted(arr, target)}")
    
    # Test three sum
    arr = [-1, 0, 1, 2, -1, -4]
    target = 0
    print(f"Three sum triplets: {three_sum(arr, target)}")
    
    # Test remove duplicates
    arr = [1, 1, 2, 2, 3, 4, 4, 5]
    new_length = remove_duplicates(arr)
    print(f"Array after removing duplicates: {arr[:new_length]}")
    
    # Test valid palindrome
    s = "A man a plan a canal Panama"
    print(f"Is palindrome: {valid_palindrome(s)}")
    
    # Test container with most water
    height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    print(f"Maximum water area: {container_with_most_water(height)}")
    
    # Test trapping rain water
    height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(f"Trapped water: {trapping_rain_water(height)}")
    
    # Test sort colors
    nums = [2, 0, 2, 1, 1, 0]
    sort_colors(nums)
    print(f"Sorted colors: {nums}")
