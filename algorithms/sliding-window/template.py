"""
Sliding Window Pattern Template
==============================

This template provides common sliding window implementations for various problem types.
"""

def fixed_size_window(arr, k):
    """
    Template for fixed-size sliding window problems.
    
    Args:
        arr: Input array
        k: Window size
    
    Returns:
        Result based on the specific problem
    """
    if len(arr) < k:
        return 0  # or appropriate default
    
    # Calculate initial window
    window_sum = sum(arr[:k])
    result = window_sum  # or appropriate initial value
    
    # Slide the window
    for i in range(k, len(arr)):
        # Remove leftmost element, add rightmost element
        window_sum = window_sum - arr[i-k] + arr[i]
        result = max(result, window_sum)  # or appropriate operation
    
    return result


def variable_size_window(arr, target):
    """
    Template for variable-size sliding window problems.
    
    Args:
        arr: Input array
        target: Target value or condition
    
    Returns:
        Result based on the specific problem
    """
    left = 0
    current_sum = 0  # or appropriate accumulator
    result = 0  # or appropriate initial value
    
    for right in range(len(arr)):
        # Expand window
        current_sum += arr[right]  # or appropriate operation
        
        # Contract window while condition is met
        while current_sum > target:  # or appropriate condition
            current_sum -= arr[left]  # or appropriate operation
            left += 1
        
        # Update result
        result = max(result, right - left + 1)  # or appropriate operation
    
    return result


def longest_substring_without_repeating(s):
    """
    Example: Longest Substring Without Repeating Characters
    
    Args:
        s: Input string
    
    Returns:
        Length of longest substring without repeating characters
    """
    if not s:
        return 0
    
    char_set = set()
    left = 0
    max_length = 0
    
    for right in range(len(s)):
        # If character is already in set, move left pointer
        while s[right] in char_set:
            char_set.remove(s[left])
            left += 1
        
        # Add current character to set
        char_set.add(s[right])
        
        # Update max length
        max_length = max(max_length, right - left + 1)
    
    return max_length


def minimum_window_substring(s, t):
    """
    Example: Minimum Window Substring
    
    Args:
        s: Source string
        t: Target string
    
    Returns:
        Minimum window substring containing all characters of t
    """
    if not s or not t:
        return ""
    
    # Count characters in target string
    target_count = {}
    for char in t:
        target_count[char] = target_count.get(char, 0) + 1
    
    left = 0
    min_len = float('inf')
    min_start = 0
    matched = 0
    window_count = {}
    
    for right in range(len(s)):
        # Add character to window
        char = s[right]
        window_count[char] = window_count.get(char, 0) + 1
        
        # Check if this character contributes to matching
        if char in target_count and window_count[char] <= target_count[char]:
            matched += 1
        
        # Try to contract window
        while matched == len(t):
            # Update minimum window
            if right - left + 1 < min_len:
                min_len = right - left + 1
                min_start = left
            
            # Remove leftmost character
            left_char = s[left]
            window_count[left_char] -= 1
            
            if left_char in target_count and window_count[left_char] < target_count[left_char]:
                matched -= 1
            
            left += 1
    
    return s[min_start:min_start + min_len] if min_len != float('inf') else ""


# Test cases
if __name__ == "__main__":
    # Test fixed size window
    arr = [1, 4, 2, 10, 23, 3, 1, 0, 20]
    k = 4
    print(f"Maximum sum of {k} consecutive elements: {fixed_size_window(arr, k)}")
    
    # Test variable size window
    arr = [2, 1, 5, 2, 3, 2]
    target = 7
    print(f"Minimum length subarray with sum >= {target}: {variable_size_window(arr, target)}")
    
    # Test longest substring without repeating
    s = "abcabcbb"
    print(f"Longest substring without repeating characters: {longest_substring_without_repeating(s)}")
    
    # Test minimum window substring
    s = "ADOBECODEBANC"
    t = "ABC"
    print(f"Minimum window substring: '{minimum_window_substring(s, t)}'")
